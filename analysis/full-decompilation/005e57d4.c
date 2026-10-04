
/* WARNING: Removing unreachable block (ram,0x005e581a) */
/* WARNING: Removing unreachable block (ram,0x005e5802) */
/* WARNING: Removing unreachable block (ram,0x005e5834) */

void __thiscall FUN_005e57d4(int param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = FUN_005dd5e1(param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 0xec) = uVar1;
  uVar2 = (param_4 & 0xff) + 0x28;
  if (0xff < uVar2) {
    uVar2 = 0xff;
  }
  uVar4 = (param_3 & 0xff) + 0x28;
  uVar6 = 0xff;
  if (uVar4 < 0x100) {
    uVar6 = uVar4;
  }
  uVar4 = (param_2 & 0xff) + 0x28;
  if (0xff < uVar4) {
    uVar4 = 0xff;
  }
  uVar1 = FUN_005dd5e1(uVar4,uVar6,uVar2);
  iVar7 = (param_4 & 0xff) - 0x28;
  *(undefined4 *)(param_1 + 0xf0) = uVar1;
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (0xff < iVar7) {
    iVar7 = 0xff;
  }
  iVar3 = (param_3 & 0xff) - 0x28;
  if (iVar3 < 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0xff;
    if (iVar3 < 0x100) {
      iVar5 = iVar3;
    }
  }
  iVar3 = (param_2 & 0xff) - 0x28;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  uVar1 = FUN_005dd5e1(iVar3,iVar5,iVar7);
  *(undefined4 *)(param_1 + 0xf4) = uVar1;
  uVar1 = FUN_005dd5e1(param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 0xe8) = uVar1;
  return;
}

