#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t* oldframe;
int w=0,h=0;

typedef struct tagBITMAPFILEHEADER
{
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

int count(uint8_t* frame,int n)
{
    int x=n%w,y=(int)n/w,sum=0;
    for (int xi=x-1; xi<x+2; xi++)
        for (int yi=y-1; yi<y+2; yi++)
            sum+=frame[((yi+h)%h)*w+(xi+w)%w];
    return sum-frame[n];
}

//int check()

int main(int argc, char **argv)
{
    char c[500], d[50];
    FILE *fname;
    FILE *fout=fopen("out.bmp", "wb");
    int  j,i, iter=0, flag=1, q;
    for(int k=1; k<argc; k++)
    {
        switch(argv[k][2])
        {
        case 'i':
            i=0;
            while(argv[k+1][i]!=0)
            {
                c[i]=argv[k+1][i];
                i++;
            }
            c[i]=0;
            //gets(c);
            fname=fopen(c, "r");
            if(!fname)
                return NULL;
            k++;
            break;
        case 111:
            i=0;
            while(argv[k+1][i]!=0)
            {
                d[i]=argv[k+1][i];
                i++;
            }
            d[i]=0;
            k++;
            break;
        case 'm':
            i=0;
            while(argv[k+1][i]!=0)
            {
                iter=iter*10+argv[k+1][i]-48;
                i++;
            }
            k++;
            flag=0;
            break;
        default:
            printf("error\n");
            break;
        }
    }




    BITMAPINFOHEADER* infohdr = NULL;
    BITMAPFILEHEADER filehdr;
    BITMAPINFOHEADER bmphdr;

    fread(&filehdr.bfType,sizeof(filehdr.bfType),1,fname);
    fread(&filehdr.bfSize,sizeof(filehdr.bfSize),1,fname);
    fread(&filehdr.bfReserved1,sizeof(filehdr.bfReserved1),1,fname);
    fread(&filehdr.bfReserved2,sizeof(filehdr.bfReserved2),1,fname);
    fread(&filehdr.bfOffBits,sizeof(filehdr.bfOffBits),1,fname);
    fread(&bmphdr.biSize,sizeof(bmphdr.biSize),1,fname);
    fread(&bmphdr.biWidth,sizeof(bmphdr.biWidth),1,fname);
    fread(&bmphdr.biHeight,sizeof(bmphdr.biHeight),1,fname);
    fread(&bmphdr.biPlanes,sizeof(bmphdr.biPlanes),1,fname);
    fread(&bmphdr.biBitCount,sizeof(bmphdr.biBitCount),1,fname);
    w = bmphdr.biWidth;
    h = bmphdr.biHeight;
    size_t  wCeil= ((int)(bmphdr.biWidth+31)/32)*4;
    uint8_t  *arr =(uint8_t*)malloc(filehdr.bfOffBits+wCeil*h);
    fseek (fname,0,SEEK_SET);
    fread(arr,1,filehdr.bfOffBits,fname);
    fwrite(arr,1,filehdr.bfOffBits,fout);
    fseek (fname,filehdr.bfOffBits,SEEK_SET);

    uint8_t *t=(uint8_t *)malloc(wCeil);
    oldframe=(uint8_t*)calloc(w*h, sizeof(uint8_t));
    char e[13]="\\example.gif";
    int yt=strlen(d);
    strcpy(&d[yt],e);
    gif= ge_new_gif(
             d,
             w, h,
             (uint8_t [])
    {
        0x00, 0xFF, 0x11,
              0xFF, 0xFF, 0xFF,
    },1,0);
    for(int i=h-1; i>=0; --i)
    {
        fread(t,sizeof(uint8_t),wCeil,fname);
        for(int j=0; j<w; ++j)
        {
            oldframe[i*w+j]=((t[j/8]>>(7-j%8))&1)^1;
        }
    }
    fclose(fname);
    int p;
    memcpy(gif->frame,oldframe,w*h*sizeof(uint8_t));
    ge_add_frame(gif,5);
    for (int it=0; (flag)||(it<iter); it++)
    {
        p=0;
        for (j = 0; j < w*h; j++)
        {
            q=count(oldframe,j);
            gif->frame[j]=(oldframe[j])?(((q==2)||(q==3))?1:0):((q==3)?1:0);
            p+=gif->frame[j];
        }
        if(p==0)
            return 0;
        memcpy(oldframe,gif->frame,w*h*sizeof(uint8_t));
        ge_add_frame(gif, 5);
    }
    ge_close_gif(gif);
    return 0;
}
