
int __thiscall FUN_005d013d(int param_1,int *param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 local_84 [2];
  undefined4 local_7c;
  undefined4 local_78;
  DWORD local_8;
  
  local_8 = timeGetTime();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x38) + 0x38))(*(int **)(param_1 + 0x38),param_2,0);
  *(int *)(param_1 + 4) = iVar1;
  if (-1 < iVar1) {
    DVar2 = timeGetTime();
    iVar1 = DVar2 - local_8;
    if (500 < iVar1) {
      puVar4 = &DAT_006d62a8;
      FUN_005bc69b(s_Changing_D3DRenderTarget_took_006d6288);
      FUN_005bc69b(iVar1);
      FUN_005bc69b(puVar4);
    }
    uVar3 = FUN_005d2c81();
    *(undefined4 *)(param_1 + 4) = uVar3;
    uVar3 = FUN_005d4539();
    *(undefined4 *)(param_1 + 4) = uVar3;
    _memset(local_84,0,0x7c);
    local_84[0] = 0x7c;
    (**(code **)(*param_2 + 0x58))(param_2,local_84);
    *(undefined4 *)(param_1 + 0x14) = local_78;
    *(undefined4 *)(param_1 + 0x18) = local_7c;
    iVar1 = *(int *)(param_1 + 4);
  }
  return iVar1;
}

