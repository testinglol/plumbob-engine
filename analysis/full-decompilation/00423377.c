
void __fastcall FUN_00423377(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 400);
  if (*(int *)(param_1 + 400) != 0) goto LAB_00423388;
  while (iVar1 = param_1, param_1 != 0) {
LAB_00423388:
    FUN_004341a6(0);
    param_1 = *(int *)(iVar1 + 0x18c);
  }
  return;
}

