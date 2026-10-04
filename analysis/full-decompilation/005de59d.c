
void __fastcall FUN_005de59d(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x8c))(8);
  if (cVar1 != '\0') {
    piVar2 = (int *)FUN_00492d2c();
    if (piVar2 == param_1) {
      FUN_005d9912(param_1);
    }
    (**(code **)(*param_1 + 0x90))(8,0);
  }
  return;
}

