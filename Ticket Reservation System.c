#include<stdio.h>
title();
cover_page();
form();
bus_ticket();
train_ticket();
launch_ticket();
movie_ticket();
int code;
struct information
{
    char name[20];
    char address[50];
    char phone_no[11];
    char ticket_no[8];
}info;
title()
{
    printf("\n\n");
    printf("\t\t\t\t***Automatic Ticket Reservation System***\n");
}
cover_page()
{
    int cover_menu;
    printf("\n\n\n");
    printf("\t1. Bus Ticket Reservation\n");
    printf("\t2. Train Ticket Reservation\n");
    printf("\t3. Launch Ticket Reservation\n");
    printf("\t4. Movie Ticket Reservation\n");
    printf("\t5. Exit\n");
    printf("\n\n\tEnter Your Choice: ");
    scanf("%d",&cover_menu);
    switch(cover_menu)
    {
    case 1:
        bus_ticket();
        break;
    case 2:
        train_ticket();
        break;
    case 3:
        launch_ticket();
        break;
    case 4:
        movie_ticket();
        break;
    case 5:
        exit(0);
        break;
    }
}
form()
{
    FILE *data;
    data=fopen("record.txt","ab+");
    fflush(stdin);
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Reservation Form***\n\n");
    printf("\tName: ");
    scanf("%s",&info.name);
    printf("\tAddress: ");
    scanf("%s",&info.address);
    printf("\tPhone No: ");
    scanf("%s",&info.phone_no);
    printf("\tTicket No: ");
    scanf("%s",&info.ticket_no);
    fwrite(&info,sizeof(info),1,data);
    fclose(data);
    printf("\n\nYour Ticket is Confirmed Successfully!");
    getch();
    main();

}
bus_ticket()
{
    system("cls");
    int bus_menu;
    printf("\n\n\n");
    printf("\t\t***Bus Ticket Reservation***\n\n");
    printf("\t1. View All Bus\n");
    printf("\t2. Reserve A Ticket\n");
    printf("\t3. Cancel A Ticket\n");
    printf("\t4. Main Menu\n");
    printf("\t5. Exit\n");
    printf("\n\n\tEnter Your Choice: ");
    scanf("%d",&bus_menu);
    switch(bus_menu)
    {
    case 1:
        view_bus();
        break;
    case 2:
        reserve_bus_ticket();
        break;
    case 3:
        cancel_ticket();
        break;
    case 4:
        main();
        break;
    case 5:
        exit(0);
        break;
    }
}
view_bus()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Bus Route Chart***\n");
    printf("\t\t---------------------\n\n");
    printf("\t Code\t\tRoute\t\tTime\n");
    printf("\t------\t\t------\t\t------\n");
    printf("\t 1001\tDhaka to Comilla\t 09.00 AM\n");
    printf("\t 1002\tDhaka to Mymensingh\t 10.00 AM\n");
    printf("\t 1003\tDhaka to Chittagong\t 11.00 AM\n");
    printf("\t 1004\tDhaka to Sylhet\t\t 12.00 PM\n");
    printf("\n\nPress Any Key to Return...");
    getch();
    bus_ticket();
}
reserve_bus_ticket()
{
    int total_seat=50, reserved_seat=0;
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Please! Reserve Your Bus Ticket***\n\n");
    printf("Enter the Bus Code: ");
    scanf("%d",&code);
    if((code==1001)||(code==1002)||(code==1003)||(code==1004))
        {
            if(reserved_seat<total_seat)
                {
                    reserved_seat++;
                    if(code==1001)
                    {
                        printf("\nTicket Price is 600 Tk.");
                        getch();
                        form();
                    }
                    else if(code==1002)
                    {
                        printf("\nTicket Price is 400 Tk.");
                        getch();
                        form();
                    }
                    else if(code==1003)
                    {
                        printf("\nTicket Price is 1000 Tk.");
                        getch();
                        form();
                    }
                    else if(code==1004)
                    {
                        printf("\nTicket Price is 800 Tk.");
                        getch();
                        form();
                    }
                }
                else
                {
                    printf("Sorry! All Seats are Reserved.\n");
                    printf("\n\nPress Any Key to Return...");
                    getch();
                    bus_ticket();
                }
        }
}
cancel_ticket()
{
    char ticket[8];
    int found=0;
    FILE *movie, *temp;
    system("cls");
    movie=fopen("record.txt","rb");
    temp=fopen("temp.txt","wb");
    printf("\n\n\n");
    printf("\t\t**Cancel Your Ticket Here***\n\n");
    printf("Enter The Ticket No: ");
    fflush(stdin);
    gets(ticket);
    while(fread(&info,sizeof(info),1,movie)==1)
    {
        if(strcmp(ticket,info.ticket_no)==0)
        {
            fwrite(&info,sizeof(info),1,temp);
        }
    }
    fclose(movie);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("\n\nYour Ticket is Canceled");
    getch();
    main();
}
train_ticket()
{
    system("cls");
    int train_menu;
    printf("\n\n\n");
    printf("\t\t***Train Ticket Reservation***\n\n");
    printf("\t1. View All Train\n");
    printf("\t2. Reserve A Ticket\n");
    printf("\t3. Cancel A Ticket\n");
    printf("\t4. Main Menu\n");
    printf("\t5. Exit\n");
    printf("\n\n\tEnter Your Choice: ");
    scanf("%d",&train_menu);
    switch(train_menu)
    {
    case 1:
        view_train();
        break;
    case 2:
        reserve_train_ticket();
        break;
    case 3:
        cancel_ticket();
        break;
    case 4:
        main();
        break;
    case 5:
        exit(0);
        break;
    }
}
view_train()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Train Route Chart***\n");
    printf("\t\t---------------------\n\n");
    printf("\t Code\t\tRoute\t\tTime\n");
    printf("\t------\t\t------\t\t------\n");
    printf("\t 2001\tDhaka to Rajshahi\t 06.00 PM\n");
    printf("\t 2002\tDhaka to Dinajpur\t 09.00 PM\n");
    printf("\t 2003\tDhaka to Chittagong\t 11.00 AM\n");
    printf("\t 2004\tDhaka to Sylhet\t\t 12.00 PM\n");
    printf("\n\nPress Any Key to Return...");
    getch();
    train_ticket();
}
reserve_train_ticket()
{
    int total_seat=200, reserved_seat=0,cl;
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Please! Reserve Your Train Ticket***\n\n");
    printf("Enter the Train Code: ");
    scanf("%d",&code);
    if((code==2001)||(code==2002)||(code==2003)||(code==2004))
        {
            if(reserved_seat<total_seat)
                {
                    reserved_seat++;
                    if(code==2001)
                    {
                        printf("\n1. First Class");
                        printf("\n2. Second Class");
                        printf("\n3. Third Class");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1500 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 800 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 500 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==2002)
                    {
                        printf("\n1. First Class");
                        printf("\n2. Second Class");
                        printf("\n3. Third Class");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 2000 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 1200 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 800 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==2003)
                    {
                        printf("\n1. First Class");
                        printf("\n2. Second Class");
                        printf("\n3. Third Class");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1000 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 600 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 400 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==2004)
                    {
                        printf("\n1. First Class");
                        printf("\n2. Second Class");
                        printf("\n3. Third Class");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1200 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 700 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 450 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                }
                else
                {
                    printf("Sorry! All Seats are Reserved.\n");
                    printf("\n\nPress Any Key to Return...");
                    getch();
                    train_ticket();
                }
        }
}
launch_ticket()
{
    system("cls");
    int launch_menu;
    printf("\n\n\n");
    printf("\t\t***Launch Ticket Reservation***\n\n");
    printf("\t1. View All Launch\n");
    printf("\t2. Reserve A Ticket\n");
    printf("\t3. Cancel A Ticket\n");
    printf("\t4. Main Menu\n");
    printf("\t5. Exit\n");
    printf("\n\n\tEnter Your Choice: ");
    scanf("%d",&launch_menu);
    switch(launch_menu)
    {
    case 1:
        view_launch();
        break;
    case 2:
        reserve_launch_ticket();
        break;
    case 3:
        cancel_ticket();
        break;
    case 4:
        main();
        break;
    case 5:
        exit(0);
        break;
    }
}
view_launch()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Launch Route Chart***\n");
    printf("\t\t---------------------\n\n");
    printf("\t Code\t\tRoute\t\tTime\n");
    printf("\t------\t\t------\t\t------\n");
    printf("\t 3001\tDhaka to Barishal\t 08.00 PM\n");
    printf("\t 3002\tDhaka to Chandpur\t 09.00 PM\n");
    printf("\t 3003\tDhaka to Bhola\t 08.30 PM\n");
    printf("\t 3004\tDhaka to Potuakhali\t\t 09.30 PM\n");
    printf("\n\nPress Any Key to Return...");
    getch();
    launch_ticket();
}
reserve_launch_ticket()
{
    int total_ticket=500, reserved_ticket=0,cl;
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Please! Reserve Your Launch Ticket***\n\n");
    printf("Enter the Launch Code: ");
    scanf("%d",&code);
    if((code==3001)||(code==3002)||(code==3003)||(code==3004))
        {
            if(reserved_ticket<total_ticket)
                {
                    reserved_ticket++;
                    if(code==3001)
                    {
                        printf("\n1. First Class Cabin");
                        printf("\n2. Normal Cabin");
                        printf("\n3. Deck");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1000 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 600 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 300 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==3002)
                    {
                        printf("\n1. First Class Cabin");
                        printf("\n2. Normal Cabin");
                        printf("\n3. Deck");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1000 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 500 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 250 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==3003)
                    {
                        printf("\n1. First Class Cabin");
                        printf("\n2. Normal Cabin");
                        printf("\n3. Deck");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1000 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 400 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 200 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==3004)
                    {
                        printf("\n1. First Class Cabin");
                        printf("\n2. Normal Cabin");
                        printf("\n3. Deck");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1500 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 800 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 450 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                }
                else
                {
                    printf("Sorry! All Tickets are Reserved.\n");
                    printf("\n\nPress Any Key to Return...");
                    getch();
                    launch_ticket();
                }
        }
}
movie_ticket()
{
    system("cls");
    int movie_menu;
    printf("\n\n\n");
    printf("\t\t***Movie Ticket Reservation***\n\n");
    printf("\t1. View All Movie List\n");
    printf("\t2. Reserve A Ticket\n");
    printf("\t3. Cancel A Ticket\n");
    printf("\t4. Main Menu\n");
    printf("\t5. Exit\n");
    printf("\n\n\tEnter Your Choice: ");
    scanf("%d",&movie_menu);
    switch(movie_menu)
    {
    case 1:
        view_movie();
        break;
    case 2:
        reserve_movie_ticket();
        break;
    case 3:
        cancel_ticket();
        break;
    case 4:
        main();
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
}
view_movie()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Movie Show Chart***\n");
    printf("\t\t---------------------\n\n");
    printf("\t Code\t\tMovie Name\t\tTime\n");
    printf("\t------\t\t----------\t\t------\n");
    printf("\t 1001\t\tRogue One: A Star Wars\t 10.00 AM\n");
    printf("\t 1002\t\tSuicide Squad\t\t 01.00 PM\n");
    printf("\t 1003\t\tMoana\t\t\t 05.00 PM\n");
    printf("\t 1004\t\tAynabaji\t\t 08.00 PM\n");
    printf("\n\nPress Any Key to Return...");
    getch();
    movie_ticket();
}
reserve_movie_ticket()
{
    int total_seat=300, reserved_seat=0,cl;
    system("cls");
    printf("\n\n\n");
    printf("\t\t***Please! Reserve Your Show Ticket***\n\n");
    printf("Enter the Show Code: ");
    scanf("%d",&code);
    if((code==4001)||(code==4002)||(code==4003)||(code==4004))
        {
            if(reserved_seat<total_seat)
                {
                    reserved_seat++;
                    if(code==4001)
                    {
                        printf("\n1. 3D-VIP");
                        printf("\n2. 3D-Normal");
                        printf("\n3. 2D-VIP");
                        printf("\n4. 2D-Normal");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1000 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 800 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 600 Tk.");
                            getch();
                            form();
                            break;
                        case 4:
                            printf("\nTicket Price is 400 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==4002)
                    {
                        printf("\n1. 3D-VIP");
                        printf("\n2. 3D-Normal");
                        printf("\n3. 2D-VIP");
                        printf("\n4. 2D-Normal");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1000 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 800 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 600 Tk.");
                            getch();
                            form();
                            break;
                        case 4:
                            printf("\nTicket Price is 400 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==4003)
                    {
                        printf("\n1. 3D-VIP");
                        printf("\n2. 3D-Normal");
                        printf("\n3. 2D-VIP");
                        printf("\n4. 2D-Normal");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 1000 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 800 Tk.");
                            getch();
                            form();
                            break;
                        case 3:
                            printf("\nTicket Price is 600 Tk.");
                            getch();
                            form();
                            break;
                        case 4:
                            printf("\nTicket Price is 400 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                    else if(code==4004)
                    {
                        printf("\n1. VIP");
                        printf("\n2. Normal");
                        printf("\n\n\tEnter Your Choice: ");
                        scanf("%d",&cl);
                        switch(cl)
                        {
                        case 1:
                            printf("\nTicket Price is 800 Tk.");
                            getch();
                            form();
                            break;
                        case 2:
                            printf("\nTicket Price is 400 Tk.");
                            getch();
                            form();
                            break;
                        }
                    }
                }
                else
                {
                    printf("Sorry! All Seats are Reserved.\n");
                    printf("\n\nPress Any Key to Return...");
                    getch();
                    movie_ticket();
                }
        }
}
main()
{
    system("cls");
    title();
    cover_page();
}
