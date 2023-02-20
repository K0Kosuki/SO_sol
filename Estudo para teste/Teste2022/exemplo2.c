#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pipe_voices[2], pipe_messages[2];
    pid_t gzip_voice, gzip_message;

    // Cria pipes para separar as sessões de voz e mensagem
    pipe(pipe_voices);
    pipe(pipe_messages);

    // Inicia processos gzip para comprimir os dados de cada tipo de sessão
    gzip_voice = fork();
    if (gzip_voice == 0)
    {
        // Filho responsável por comprimir sessões de voz
        close(pipe_voices[1]);   // fecha o lado de escrita do pipe
        dup2(pipe_voices[0], 0); // redireciona a entrada padrão para o pipe
        close(pipe_voices[0]);
        execlp("gzip", "gzip", "-c", "- > V.gz", (char)NULL);
    }
    else
    {
        gzip_message = fork();
        if (gzip_message == 0)
        {
            // Filho responsável por comprimir sessões de mensagem
            close(pipe_messages[1]);
            dup2(pipe_messages[0], 0);
            close(pipe_messages[0]);
            execlp("gzip", "gzip", "-c", "- > M.gz", (char)NULL);
        }
        else
        {
            // Pai lê os dados do stdin e separa as sessões de voz e mensagem
            close(pipe_voices[0]);
            close(pipe_messages[0]);
            char line[1024];
            int n;
            while (fgets(line, sizeof(line), stdin))
            {
                if (line[0] == 'V')
                {
                    write(pipe_voices[1], line, strlen(line));
                }
                else if (line[0] == 'M')
                {
                    write(pipe_messages[1], line, strlen(line));
                }
            }
            close(pipe_voices[1]);
            close(pipe_messages[1]);
            waitpid(gzip_voice, NULL, 0);
            waitpid(gzip_message, NULL, 0);
        }
    }
    return 0;
}