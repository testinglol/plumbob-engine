
void __thiscall FUN_004d4f8f(int *param_1,undefined4 param_2,undefined4 param_3)

{
  SHORT SVar1;
  
  if ((char)param_1[0x24] != '\0') {
    *(undefined1 *)((int)param_1 + 0x45) = 0;
    if ((char)param_1[0x11] == '\0') {
      if (param_1[1] == 0) {
        SVar1 = GetKeyState(1);
        if (-1 < SVar1) {
          FUN_0051eaec();
          FUN_00586fdc(0);
          FUN_004d5456(param_2,param_3);
        }
      }
      else if (param_1[1] == 2) {
        param_1[1] = 0;
      }
    }
    else {
      (**(code **)(*param_1 + 0x38))();
      *(undefined1 *)(param_1 + 0x11) = 0;
    }
    FUN_005d9912(param_1[0x20]);
  }
  return;
}

