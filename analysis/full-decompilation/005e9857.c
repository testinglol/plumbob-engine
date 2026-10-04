
void __fastcall FUN_005e9857(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x8c))(1);
  if (cVar1 == '\0') {
    param_1[0x39] = 0;
    param_1[0x38] = 1;
    FUN_005e98c3();
  }
  FUN_005de626();
  return;
}

