
void FUN_0055ffd5(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  uVar5 = param_3[1];
  uVar6 = param_3[3];
  uVar7 = *param_3;
  uVar8 = param_3[2];
  if (param_1 != (int *)0x0) {
    cVar9 = (**(code **)(*param_1 + 0x20))(1);
    if (cVar9 != '\0') {
      (**(code **)(*param_1 + 0x48))(param_4,uVar1,uVar2,uVar3,uVar5);
      (**(code **)(*param_1 + 0x48))(param_4,uVar1,uVar6,uVar3,uVar4);
      (**(code **)(*param_1 + 0x48))(param_4,uVar1,uVar5,uVar7,uVar6);
      (**(code **)(*param_1 + 0x48))(param_4,uVar8,uVar5,uVar3,uVar6);
      (**(code **)(*param_1 + 0x24))(1);
    }
  }
  return;
}

