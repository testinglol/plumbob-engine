
void __thiscall FUN_00604076(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  if ((param_1[0x35] - param_1[0x34]) / 0x1c == 1) {
LAB_0060410b:
    iVar4 = *param_1;
  }
  else {
    if ((param_1[0x35] - param_1[0x34]) / 0x1c != 2) {
      uVar6 = 0;
      uVar3 = (param_1[0x35] - param_1[0x34]) / 0x1c;
      if (uVar3 != 0) {
        piVar5 = (int *)param_1[0x34];
        do {
          piVar1 = (int *)*piVar5;
          if ((piVar1 == (int *)0x0) ||
             (((*piVar1 == 0 && ((short)piVar1[1] == 0)) && (*(short *)((int)piVar1 + 6) == 0)))) {
            iVar4 = *param_1;
            goto LAB_0060410f;
          }
          uVar6 = uVar6 + 1;
          piVar5 = piVar5 + 7;
        } while (uVar6 < uVar3);
      }
      goto LAB_0060410b;
    }
    iVar2 = (*(code *)PTR_FUN_006d7088)(*(undefined4 *)(param_1[0x34] + 4),s_Primary_006d919c,7);
    iVar4 = *param_1;
    if (iVar2 == 0) {
      uVar6 = 1;
      goto LAB_0060410f;
    }
  }
  uVar6 = 0;
LAB_0060410f:
  (**(code **)(iVar4 + 0xa0))(param_2,param_3,uVar6);
  return;
}

