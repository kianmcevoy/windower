#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void OutputWindow(FILE* fp, char* type, int size)
{
	// TODO: check "size" is a sensible value..................

	if (strcmp(type, "hamming") == 0)
	{
		fprintf(fp, "static const float %s[%d] =\n{\n" , type, size);
        
        for(int n = 0; n < size; n++)
		{
			double output = 0.54 - 0.46 * cos((2*M_PI*n) / (size-1));
			fprintf(fp, "\t%.8f,\n", output);
		}

		fprintf(fp, "};\n\n");
	}

	else if (strcmp(type, "hanning") == 0)
	{
		fprintf(fp, "static const float %s[%d] =\n{\n" , type, size);
       
        for(int n = 0; n < size; n++)
		{
			double output = 0.5 - 0.5 * cos((2*M_PI*n) / (size-1));
			fprintf(fp, "\t%.8f,\n", output);
		}

		fprintf(fp, "};\n\n");
	}

    else if (strcmp(type, "hann") == 0)
	{
		fprintf(fp, "static const float %s[%d] =\n{\n" , type, size);
       
        for(int n = 0; n < size; n++)
		{
			double output = 0.5 * (1 - cos((2*M_PI*n) / (size-1)));
			fprintf(fp, "\t%.8f,\n", output);
		}

		fprintf(fp, "};\n\n");
	}

	else if (strcmp(type, "gauss") == 0)
	{
		double spread = 0.125;
		double peak = 0.5;
        double normFactor = sqrt(2*(M_PI*(spread*spread)));

		fprintf(fp, "static const float %s[%d] =\n{\n" , type, size);

        for(int n = 0; n < size; n++)
		{
			double index = (double)n/size;
			double output = normFactor*(exp((-1*(index-peak)*(index-peak))/(2*spread*spread))/(spread*sqrt(2*M_PI)));
 			fprintf(fp, "\t%.8f,\n", output);
		}

		fprintf(fp, "};\n\n");
	}

    else if (strcmp(type, "blackman") == 0)
	{
		fprintf(fp, "static const float %s[%d] =\n{\n" , type, size);
       
        for(int n = 0; n < size; n++)
		{
            double factor = (2*M_PI)/(size-1);
			double output = 0.42 - 0.5*cos(factor*n)+0.08*cos(2*(factor*n));
			fprintf(fp, "\t%.8f,\n", output);
		}

		fprintf(fp, "};\n\n");
	}

    else if (strcmp(type, "blackman-harris") == 0)
	{
		fprintf(fp, "static const float %s[%d] =\n{\n" , type, size);
       
        for(int n = 0; n < size; n++)
		{
            double factor = (2*M_PI)/(size-1);
			double output = 0.35875 - 0.48829 * cos(factor*n) + 0.14128 * cos(2*factor*n) - 0.01168 * cos(3*factor*n);
			fprintf(fp, "\t%.8f,\n", output);
		}

		fprintf(fp, "};\n\n");
	}

	else
	{
		fprintf(stderr, "no matching window type \"%s\"\n", type);
	}
}


int main(int argc, char **argv)
{

    char* windowType[argc/2];
    int windowSize[argc/2];

    FILE *outputFile = fopen("windows.h", "w+");

    if (outputFile == NULL)
	{
		fprintf(stderr,"File open error\n");
		exit(1);
	}

    if ((argc < 3) || (argc % 2 == 0))
    {
        fprintf(stderr, "incorrect number of aruments\nshould be of type <windowSize> <windowType>\n");
		exit(1);
    }

    for(int i = 1; i < argc; i+=2)
    {
		OutputWindow(outputFile, argv[i], atoi(argv[i+1]));
    }

    return 0;
}
// End