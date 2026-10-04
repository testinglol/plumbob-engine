
uint __fastcall FUN_005f95a3(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint local_8;
  
  iVar4 = 0;
  piVar5 = (int *)(param_1 + 0x80);
  local_8 = param_1;
  do {
    piVar1 = (int *)*piVar5;
    uVar3 = 0;
    if (piVar1 == (int *)0x0) break;
    uVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,&local_8);
    if ((uVar3 == 0) && ((local_8 & 5) != 0)) {
      uVar2 = *(undefined4 *)(param_1 + 0x80 + iVar4 * 4);
      *(undefined4 *)(param_1 + 0xa0) = uVar2;
      return CONCAT31((int3)((uint)uVar2 >> 8),1);
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar4 < 8);
  return uVar3 & 0xffffff00;
}

