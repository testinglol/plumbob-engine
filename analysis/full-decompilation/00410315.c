
int __fastcall FUN_00410315(int param_1)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_10 = 0;
  local_8 = 0;
  iVar4 = *(int *)(param_1 + 0x130) - *(int *)(param_1 + 300) >> 2;
  if (0 < iVar4) {
    do {
      puVar1 = (undefined4 *)FUN_004102ab(local_8);
      puVar2 = (undefined2 *)FUN_00425769(*puVar1);
      if (puVar2 != (undefined2 *)0x0) {
        FUN_0042a8e3(*puVar2);
        iVar3 = FUN_0041f662(7,0x99e81bec,&local_10);
        local_c = local_c + iVar3;
      }
      local_8 = local_8 + 1;
    } while (local_8 < iVar4);
  }
  return (int)(short)local_c;
}

