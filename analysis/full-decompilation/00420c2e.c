
void __fastcall FUN_00420c2e(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 4) + 4);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(undefined4 *)(param_1 + 4) = uVar1;
  }
  return;
}

