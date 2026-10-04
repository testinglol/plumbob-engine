
uint __thiscall FUN_004069f8(int param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined2 uVar5;
  int iVar3;
  uint uVar4;
  int iVar6;
  short sVar7;
  int *piVar8;
  
  iVar6 = 0;
  uVar2 = FUN_004659fc(0);
  sVar7 = 0;
  piVar8 = (int *)(param_1 + 0xc);
  do {
    uVar5 = (undefined2)((uint)uVar2 >> 0x10);
    if ((int *)*piVar8 == (int *)0x0) break;
    sVar1 = (**(code **)(*(int *)*piVar8 + 0x34))(param_2);
    sVar7 = sVar7 + sVar1;
    iVar3 = FUN_00401f6f();
    if (iVar3 != 0) {
      uVar2 = FUN_00401f6f();
      uVar4 = FUN_004659fc(uVar2);
      return uVar4 & 0xffff0000;
    }
    iVar6 = iVar6 + 1;
    piVar8 = piVar8 + 5;
    uVar2 = 0;
    uVar5 = 0;
  } while (iVar6 < 8);
  return CONCAT22(uVar5,sVar7);
}

