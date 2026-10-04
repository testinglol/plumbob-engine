
void FUN_00401ae2(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_8;
  
  local_8 = 0x14;
  iVar2 = FUN_00401beb(param_1,&local_8);
  iVar4 = 1;
  if (local_8 != 1) {
    puVar3 = (undefined4 *)(iVar2 + param_1);
    *(undefined4 **)(&DAT_006de560 + (param_1 + 7U >> 3) * 4) = puVar3;
    puVar1 = puVar3;
    if (local_8 != 2) {
      do {
        puVar3 = (undefined4 *)((int)puVar1 + param_1);
        *puVar1 = puVar3;
        iVar4 = iVar4 + 1;
        puVar1 = puVar3;
      } while (local_8 + -1 != iVar4);
    }
    *puVar3 = 0;
  }
  return;
}

