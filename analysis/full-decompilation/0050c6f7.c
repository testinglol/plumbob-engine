
void __fastcall FUN_0050c6f7(int *param_1)

{
  char cVar1;
  
  if (param_1[0x3c] != 0) {
    FUN_004cb761(&stack0x00000004);
    cVar1 = (**(code **)(*param_1 + 0x8c))(1);
    if (cVar1 != '\0') {
      FUN_0050c729();
    }
  }
  return;
}

