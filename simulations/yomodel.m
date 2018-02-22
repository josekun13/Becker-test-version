g=9.81;
m=0.18;
R=0.0625;
j_w=(m*R^2)/2;
M=4.14;
W=0.6;
D=0.2;
H=1;
L=0.0386;
j_psi=(M*L^3)/3;
j_phi=(M*(W^2+D^2))/12;
j_m=1*10^(-5);
R_m=2.4;
K_b=0.57295;
K_t=0.24;
n=1;
f_m=0.0022;
f_w=0;
alpha=(n*K_t)/R_m;
beta=(n*K_t*K_b)/R_m+f_m;
A_1=zeros(4,4);
A_2=zeros(2,2);
B_1=zeros(4,2);
B_2=zeros(2,2);
D_1=zeros(4,2);
D_2=zeros(2,2);
C_1=eye(4);
C_2=eye(2);
E=zeros(2,2);
E(1,1)=((2*m+M)*R^2)+(2*j_w)+(2*n^2*j_m);
E(1,2)=(M*L*R)-(2*n^2*j_m);
E(2,1)=E(1,2);
E(2,2)=(M*L^2)+j_psi+(2*n^2*j_m);
dete=det(E);
A_1(3,2)=-(g*m*L*E(1,2))/dete;
A_1(4,2)=(g*M*L*E(1,1))/dete;
A_1(3,3)=(-2*((beta+f_w)*E(2,2)+beta*E(1,2)))/dete;
A_1(4,3)=(2*((beta+f_w)*E(1,2)+beta*E(1,1)))/dete;
A_1(3,4)=(2*beta*(E(2,2)+E(1,2)))/dete;
A_1(4,4)=(-2*beta*(E(1,1)+E(1,2)))/dete;
A_1(1,3)=1;
A_1(2,4)=1;
B_1(3,1)=(alpha*(E(2,2)+E(1,2)))/dete;
B_1(3,2)=B_1(3,1);
B_1(4,1)=(-alpha*(E(1,1)+E(1,2)))/dete;
B_1(4,2)=B_1(4,1);
I=(1/2)*m*W^2+j_phi+((W^2)/(2*R^2))*(j_w+n^2*j_m);
J=((W^2)/(2*R^2))*(beta+f_w);
K=((W)/(2*R))*alpha;
A_2(1,2)=1;
A_2(2,2)=-J/I;
B_2(2,1)=-K/I;
B_2(2,2)=-B_2(2,1);
[num,den]=ss2tf(A_1,B_1,C_1,D_1,2);
%%
Co = ctrb(A_1,B_1);
unco = length(A_1) - rank(Co);
Ob = obsv(A_1,C_1);
unob = length(A_1)-rank(Ob);
%%
Co2 = ctrb(A_2,B_2);
unco2 = length(A_2) - rank(Co2);
Ob2 = obsv(A_2,C_2);
unob2 = length(A_2)-rank(Ob2);
%
Q_1=[1,0,0,0,0
    0,1e6,0,0,0
    0,0,1,0,0
    0,0,0,1,0
    0,0,0,0,1e-8];
R_1=1e2*eye(2);
A_bar=[A_1,zeros(4,1);C_1(1,:),0];
B_bar=[B_1;0,0];
K4222=lqr(A_bar,B_bar,Q_1,R_1);

