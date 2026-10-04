
bool FUN_00604a0f(LPMSG param_1)

{
  BOOL BVar1;
  
  BVar1 = PeekMessageA(param_1,(HWND)0x0,0,0,1);
  return BVar1 != 0;
}

