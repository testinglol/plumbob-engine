
undefined4 __fastcall FUN_005231fb(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x110) + 0xf8);
  if (-1 < iVar1) {
    puVar3 = (undefined4 *)FUN_00425e2d();
    local_8 = -1;
    puVar4 = (undefined4 *)*puVar3;
    while ((puVar4 != (undefined4 *)puVar3[1] && (local_8 < iVar1))) {
      if ((puVar4 != (undefined4 *)0x0) && (cVar2 = FUN_00522fd0(*puVar4), cVar2 != '\0')) {
        local_8 = local_8 + 1;
      }
      puVar4 = puVar4 + 1;
    }
    if (local_8 == iVar1) {
      return puVar4[-1];
    }
  }
  return 0;
}

