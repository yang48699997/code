;assume cs:codesg,ds:datasg

datasg1 segment
    db "1975","1976","1977","1978","1979","1980","1981","1982"
    db "1983","1984","1985","1986","1987","1988","1989","1990"
    db "1991","1992","1993","1994","1995"     ;��� 
datasg1 ends   

datasg2 segment
    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479
    dd 140317,197514,345980,590827,803530,1183000,1843000,2759000
    dd 3753000,4649000,5937000                ;����
datasg2 ends

datasg3 segment
    dw 3,7,10,13,28,38,130,220,476,778,1001,1442,2258
    dw 2793,4037,5635,8226,11542,14430,15257,17800 ;��Ա
datasg3 ends

tablesg segment
    db 21 dup("year summ ne ?? ")   ;
tablesg ends

codesg segment
start:
    mov cx,21 ;����ѭ��������21�꣬������Ϊ21��  
    mov si,0
    mov di,0
    mov bx,0
    mov ax,tablesg
    mov es,ax   
  s:mov ax,datasg1
    mov ds,ax
    mov al,[si]
    mov es:[bx],al
    mov al,[si+1]
    mov es:[bx+1],al                                             
    mov al,[si+2]
    mov es:[bx+2],al
    mov al,[si+2]
    mov es:[bx+2],al  
    mov al,[si+3]
    mov es:[bx+3],al   ;�������������
                 
    mov ax,datasg2
    mov ds,ax
    mov ax,[si]
    mov es:[bx+5],ax
    mov ax,[si+2]
    mov es:[bx+7],ax   ;��������������
    
    mov ax,datasg3
    mov ds,ax
    mov ax,[di]
    mov es:[bx+10],ax  ;����Ա����������
            
    mov ax,es:[5]
    mov dx,es:[7]
    div word ptr es:[bx+10]
    mov es:[bx+13],ax  ;����ƽ�����ʣ�����������
    
    add bx,16
    add si,4
    add di,2     ;����ƫ����
    loop s       
            
    mov ax, 4c00h ;�˳�����
    int 21h    
codesg ends

end start ; ����

