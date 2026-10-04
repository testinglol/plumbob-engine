
void __fastcall FUN_005fa8c5(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x24))();
  if (cVar1 == '\0') {
    if ((code *)param_1[0x1e] != (code *)0x0) {
      (*(code *)param_1[0x1e])(param_1[0xc]);
      return;
    }
  }
  else {
    FUN_005fa8e9();
  }
  return;
}

