
void __thiscall FUN_004e61c6(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  uint3 uVar7;
  uint uVar6;
  int *piVar8;
  int local_8;
  
  if (param_2 == 0) {
    local_8 = 0;
  }
  else {
    iVar2 = 1;
    if ((param_2 == 1) || (iVar2 = 2, local_8 = param_1, param_2 == 2)) {
      local_8 = iVar2;
    }
  }
  if (((*DAT_006e486c != 0) && (iVar2 = *(int *)(*DAT_006e486c + 0x14), iVar2 != 0)) &&
     (piVar8 = *(int **)(iVar2 + 0x84), piVar8 != *(int **)(iVar2 + 0x88))) {
    do {
      piVar1 = (int *)*piVar8;
      if (((piVar1 != (int *)0x0) &&
          (piVar3 = (int *)(**(code **)(*piVar1 + 0x8c))(), piVar3 != (int *)0x0)) &&
         (param_1 = (**(code **)(*piVar3 + 0xac))(), param_1 != 0)) {
        FUN_005a18a4(local_8);
        uVar7 = (uint3)((uint)extraout_ECX >> 8);
        uVar6 = CONCAT31(uVar7 >> 1,(char)(CONCAT31(uVar7,(char)piVar1[0x188]) >> 1)) & 0xffffff01;
        uVar4 = CONCAT31((int3)((uint)(piVar1 + 0x188) >> 8),(char)piVar1[0x188]) & 0xffffff01;
        uVar5 = FUN_00435294(uVar4,uVar6);
        FUN_005a1917(uVar5,uVar4,uVar6);
      }
      piVar8 = piVar8 + 1;
    } while (piVar8 != *(int **)(iVar2 + 0x88));
  }
  FUN_005d14fd(local_8);
  if ((param_2 == 0) || (param_2 == 1)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
  }
  FUN_0056f3e0(uVar5,param_1);
  if ((int *)DAT_006e486c[1] != (int *)0x0) {
    (**(code **)(*(int *)DAT_006e486c[1] + 0x48))();
  }
  return;
}

