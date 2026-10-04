
void __thiscall FUN_004ecee7(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004071be(*param_2,param_2[1]);
  iVar2 = 1;
  do {
    iVar1 = iVar2 + *(int *)(param_1 + 0xd4) * 4;
    if (iVar1 <= *(int *)(param_1 + 0xdc)) {
      FUN_0042eab4(*(int *)(param_1 + 0xe0) + -4 + iVar1 * 4);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}

