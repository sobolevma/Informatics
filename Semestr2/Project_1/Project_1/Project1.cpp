#include <windows.h>
#include <time.h>
int a0=0;	
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
HINSTANCE hInst ;
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "HelloWin" ;
     HWND        hwnd ;
     MSG         msg ;
     WNDCLASSEX  wndclass ;

     wndclass.cbSize        = sizeof (wndclass) ;
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
     wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;
     
     RegisterClassEx (&wndclass) ;

     hwnd = CreateWindow (szAppName,        // 
		     "Мой проект",   // 
                   WS_OVERLAPPEDWINDOW,     // 
                   CW_USEDEFAULT,           // 
                   CW_USEDEFAULT,           // 
                   CW_USEDEFAULT,           // 
                   CW_USEDEFAULT,           // 
                   NULL,                    // 
                   NULL,                    // 
                   hInstance,               // 
		   NULL) ;		   // 

     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;

     while (GetMessage (&msg, NULL, 0, 0))
          {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
          }
     return msg.wParam ;
     }

#define BTN_WIDTH        150
#define BTN_HEIGHT       20
LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {
     HDC         hdc ;
     PAINTSTRUCT ps ;
     RECT        rect ;
	 static HWND  hwndButton1, hwndButton2, hwndButton3;
	 static char txt[32]="";
	 int loword,hiword;
	 static int fpic=0;
	 static HPEN hpen,hpen2,hpen3,hpen4;
	 static HBRUSH hbrush,hbrush2,hbrush3,hbrush4;
	 
	 switch (iMsg)
          {
          case WM_CREATE :
			  srand(time(0));
			
        
			  hdc = GetDC (hwnd) ;
			  hwndButton1 = CreateWindow ("button", "Создать",
                                  WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                  100, 500, BTN_WIDTH, BTN_HEIGHT,
                                  hwnd, (HMENU) 1, hInst, NULL) ;
			  
			  hwndButton2 = CreateWindow ("button", "Удалить",
                                  WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                  300, 500, BTN_WIDTH, BTN_HEIGHT,
                                  hwnd, (HMENU) 2, hInst, NULL) ;

				hwndButton3 = CreateWindow ("button", "ФИО",
                                  WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,
                                  500, 500, BTN_WIDTH, BTN_HEIGHT,
                                  hwnd, (HMENU) 3, hInst, NULL) ;		

               return 0 ;
		
		 
   
		  
		  
		  
		  
	case WM_TIMER: 	           
		   a0+=8;          
           InvalidateRect(hwnd,NULL,TRUE); 
     
      return 0;


			
				
		case WM_LBUTTONDOWN :				
			SetTimer(hwnd,1,30,NULL);          
			  return 0;
		
		case WM_RBUTTONDOWN :			
			KillTimer(hwnd,1);
			  return 0;

		  
		  
		  case WM_COMMAND :
			hpen = CreatePen(PS_SOLID, 2,RGB(0,0,255));
			hpen2= CreatePen(PS_SOLID, 2,RGB(128,128,128));
			hpen3= CreatePen(PS_SOLID, 2,RGB(255,0,0));
			hpen4=CreatePen(PS_SOLID, 2,RGB(0,255,255));
			hbrush = CreateSolidBrush (RGB(0,0,255));
			hbrush2=CreateSolidBrush (RGB(128,128,128));
			hbrush3=CreateSolidBrush (RGB(255,0,0));
			hbrush4=CreateSolidBrush (RGB(0,255,255));
			loword=LOWORD(wParam);
			hiword=HIWORD(wParam);
			switch(loword){
				case 1:	fpic=1; break;
				case 2:	fpic=2; break;
				case 3:	strcpy(txt,"Соболев М.А."); fpic=3; break;
				default:	strcpy(txt,"Неизвестно что"); break;
			}
			InvalidateRect (hwnd, NULL, TRUE) ;
			return 0 ;

            
			

		

			 

          case WM_PAINT :
	       hdc = BeginPaint (hwnd, &ps) ;
               GetClientRect (hwnd, &rect) ;			
				switch(fpic){
				case 1: 									
					SelectObject (hdc, hbrush);
					SelectObject (hdc, hpen);
					Rectangle (hdc, 200-a0, 230, 450-a0, 280);
					Rectangle (hdc, 250-a0, 190, 400-a0, 230);
					SelectObject (hdc, hbrush2);
					SelectObject (hdc, hpen2);
					Ellipse (hdc, 210-a0, 280, 260-a0, 330);
					Ellipse (hdc, 390-a0, 280, 440-a0, 330);
					SelectObject (hdc, hbrush3);
					SelectObject (hdc, hpen3);
					Rectangle (hdc, 258-a0, 200, 296-a0, 270);
					Rectangle (hdc, 354-a0, 200, 392-a0, 270);
					SelectObject (hdc, hbrush4);
					SelectObject (hdc, hpen4);
					Rectangle (hdc, 302-a0, 200, 348-a0, 230);
					if(450-a0<-100) a0=-2000;
				
					break;
				case 2: 
					
					break;
					case 3:
						
					TextOut (hdc, 100, 300, txt, strlen(txt)) ;
					break;
				}  				

	       EndPaint (hwnd, &ps) ;
               return 0 ;

          case WM_DESTROY :
               PostQuitMessage (0) ;
               return 0 ;
          }

     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
     }
	

