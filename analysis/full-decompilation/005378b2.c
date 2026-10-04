
void __fastcall FUN_005378b2(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    _memset(param_1 + 0x35,0,0xc);
  }
  FUN_005dbf4d();
  return;
}

