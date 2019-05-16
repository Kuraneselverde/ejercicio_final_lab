#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;
int main() 
{
    ofstream outfile;
	outfile.open("bifur.dat");
    double fd=1.35;
    double fdi=1.49;
    double dfd=0.0005;
    double w0=0; 
    double theta=0.2;
    double t=0;
    double np=600000;
    double gam=0.5;
    double fref=2.0/3.0; 
    double dt=(2*M_PI/fref)*(1000.0/np);
    
    while (fd<fdi)
    {
        for (int p=0; p<np ;p++)
        {

            if(p>np*(1.0/2) && p%600==0)
            {
                outfile << fd <<" "<< theta << endl;
            }

            w0=w0-(sin(theta)+(gam*w0)-(fd*sin(fref*t)))*dt;
            theta=theta+w0*dt;
            t+=dt;
            
            while (theta<M_PI){
                theta+=2*M_PI;
            }
            while (theta>M_PI){
                theta-=2*M_PI;
            }

        }
        fd+=dfd;
    }
    
    outfile.close();

    return 0;
}