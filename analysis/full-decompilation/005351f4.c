
void __fastcall FUN_005351f4(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x37] = 0;
  }
  FUN_005dbf4d();
  return;
}

