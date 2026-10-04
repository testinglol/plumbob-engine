
uint __thiscall FUN_005f972f(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int local_8;
  
  iVar4 = 0;
  piVar5 = (int *)(param_1 + 0x80);
  local_8 = param_1;
  while( true ) {
    piVar1 = (int *)*piVar5;
    if (piVar1 == (int *)0x0) {
      iVar4 = (**(code **)(*DAT_006fed6c + 0x14))
                        (DAT_006fed6c,*(undefined4 *)(param_1 + 0x80 + iVar4 * 4),param_2);
      return CONCAT31((int3)((uint)-iVar4 >> 8),'\x01' - (iVar4 != 0));
    }
    uVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,&local_8);
    if ((uVar3 == 0) && (local_8 == 0)) break;
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 1;
    if (7 < iVar4) {
      return uVar3 & 0xffffff00;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x80 + iVar4 * 4);
  *param_2 = uVar2;
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}

