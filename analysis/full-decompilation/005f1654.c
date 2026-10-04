
undefined4 FUN_005f1654(HWND param_1,int param_2,WPARAM param_3,uint param_4)

{
  int *piVar1;
  HWND hWnd;
  
  piVar1 = DAT_006fecac;
  if (param_2 == 1) {
    if ((DAT_006f29ed == '\0') && (hWnd = ImmGetDefaultIMEWnd(param_1), hWnd != (HWND)0x0)) {
      DestroyWindow(hWnd);
    }
    return 0;
  }
  if (param_2 == 0x10d) {
    if (DAT_006feca8 != 0) {
      FUN_005f0f07();
    }
  }
  else if (param_2 == 0x10e) {
    if (DAT_006feca8 != 0) {
      FUN_005f0f3e();
    }
  }
  else if (param_2 == 0x10f) {
    if (DAT_006feca8 != 0) {
      FUN_005f0f59(param_1,param_4);
    }
  }
  else if (param_2 == 0x281) {
    if (param_3 == 0) {
      param_4 = param_4 & 0x3ffffff0;
    }
    else {
      param_4 = param_4 | 0xc000000f;
    }
    DefWindowProcA(param_1,0x281,param_3,param_4);
  }
  else if (param_2 == 0x282) {
    if (param_3 == 3) {
      if (DAT_006fecac != (int *)0x0) {
        FUN_005f1306(param_1,param_4);
      }
    }
    else if (param_3 == 4) {
      if (DAT_006fecac != (int *)0x0) {
        (**(code **)(*DAT_006fecac + 0x98))();
      }
    }
    else if (param_3 == 5) {
      if (DAT_006fecac != (int *)0x0) {
        (**(code **)(*DAT_006fecac + 0x94))();
        (**(code **)(*piVar1 + 0x44))();
        FUN_005f1306(param_1,param_4);
      }
      return 1;
    }
  }
  else if (param_2 != 0x284) {
    return 0;
  }
  return 1;
}

