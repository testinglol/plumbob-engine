
void __fastcall FUN_005e9889(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x8c))(1);
  if ((cVar1 != '\0') && ((char)param_1[0x3a] != '\0')) {
    FUN_005dae65(param_1);
    *(undefined1 *)(param_1 + 0x3a) = 0;
  }
  FUN_005de633();
  return;
}

