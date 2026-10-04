
void __thiscall FUN_0049ff0e(uint *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_8;
  
  iVar6 = 0;
  local_8 = 0;
  iVar3 = (**(code **)*param_2)();
  if (0 < iVar3) {
    cVar1 = *(char *)param_2[1];
    if (cVar1 == 'C') {
      local_8 = 3;
    }
    else if (cVar1 == 'H') {
      local_8 = 0;
    }
    else if (cVar1 == 'M') {
      local_8 = 1;
    }
    else if (cVar1 == 'S') {
      local_8 = 2;
    }
  }
  uVar5 = 0;
  iVar3 = (**(code **)*param_2)();
  if (iVar3 < 10) {
    uVar7 = 0;
  }
  else {
    uVar2 = *(undefined1 *)(param_2[1] + 3);
    iVar3 = FUN_004a0005(*(undefined1 *)(param_2[1] + 2));
    iVar6 = FUN_004a0005(uVar2);
    iVar6 = iVar3 * 0x10 + iVar6;
    uVar2 = *(undefined1 *)(param_2[1] + 6);
    iVar3 = FUN_004a0005(*(undefined1 *)(param_2[1] + 5));
    iVar4 = FUN_004a0005(uVar2);
    uVar5 = iVar3 * 0x10 + iVar4;
    uVar2 = *(undefined1 *)(param_2[1] + 9);
    iVar3 = FUN_004a0005(*(undefined1 *)(param_2[1] + 8));
    iVar4 = FUN_004a0005(uVar2);
    uVar7 = iVar3 * 0x10 + iVar4;
  }
  *param_1 = ((iVar6 << 8 | uVar5) << 8 | uVar7) << 8 | local_8;
  return;
}

