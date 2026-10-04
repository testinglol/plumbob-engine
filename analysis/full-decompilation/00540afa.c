
void __fastcall FUN_00540afa(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int local_4;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  local_4 = 2;
  do {
    puVar1 = (undefined4 *)*puVar2;
    for (piVar4 = (int *)*puVar1; piVar4 != (int *)puVar1[1]; piVar4 = piVar4 + 1) {
      iVar3 = 0x18;
      do {
        if (*(int *)(*piVar4 + iVar3) != 0) {
          FUN_0053d9dd(0xff,0);
          FUN_0053dace(0xff,1);
          FUN_0053da3a();
        }
        iVar3 = iVar3 + 4;
      } while (iVar3 < 0x20);
      puVar1 = (undefined4 *)*puVar2;
    }
    puVar2 = puVar2 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}

