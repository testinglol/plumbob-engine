
void __thiscall FUN_0053561a(int param_1,undefined4 *param_2)

{
  size_t sVar1;
  
  if (*(int *)(param_1 + 0x50) != *(int *)(param_1 + 0x4c)) {
    sVar1 = _strlen(&DAT_006c2b5c);
    FUN_00412d8a(&DAT_006c2b5c,&DAT_006c2b5c + sVar1);
  }
  FUN_00412d8a(*param_2,param_2[1]);
  FUN_00535494();
  return;
}

