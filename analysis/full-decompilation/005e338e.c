
bool __thiscall
FUN_005e338e(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,char param_6,char param_7)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  byte bVar9;
  
  bVar9 = 0;
  iVar6 = (-(uint)(param_6 != '\0') & 0x70) - 0x38;
  uVar5 = FUN_005dfe3b(param_3,param_4,param_5);
  uVar7 = FUN_005e34c5(param_1,param_3,param_4,param_5,iVar6);
  uVar8 = FUN_005e34c5(param_1,param_3,param_4,param_5,-iVar6);
  if (param_7 != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x20))(1);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*param_1 + 0x40))(uVar5,param_2,0);
      bVar9 = 1 - (cVar1 != '\0');
      (**(code **)(*param_1 + 0x24))(1);
    }
  }
  cVar1 = (**(code **)(*param_1 + 0x20))(4);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x7c))(*param_2,param_2[1],param_2[2] + -1,param_2[1],uVar7,1);
    cVar2 = (**(code **)(*param_1 + 0x7c))(*param_2,param_2[1],*param_2,param_2[3] + -1,uVar7,1);
    cVar3 = (**(code **)(*param_1 + 0x7c))
                      (param_2[2] + -1,param_2[1],param_2[2] + -1,param_2[3] + -1,uVar8,1);
    cVar4 = (**(code **)(*param_1 + 0x7c))
                      (*param_2,param_2[3] + -1,param_2[2] + -1,param_2[3] + -1,uVar8,1);
    bVar9 = bVar9 | 1U - (cVar1 != '\0') | 1U - (cVar2 != '\0') | 1U - (cVar3 != '\0') |
            1U - (cVar4 != '\0');
    (**(code **)(*param_1 + 0x24))(4);
  }
  return bVar9 == 0;
}

