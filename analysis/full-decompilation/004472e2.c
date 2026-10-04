
void __thiscall FUN_004472e2(int param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  int local_1c;
  int local_14;
  
  if ((((param_2 != 0) && (*(char *)(param_1 + 0x11) != '\0')) && (*(int *)(param_1 + 200) != 0)) &&
     ((uVar2 = *(uint *)(param_2 + 0x114), param_2 != 0 && (*(int *)(param_1 + 0xcc) != 0)))) {
    (**(code **)(**(int **)(param_1 + 0xcc) + 0x50))(1);
    sVar1 = *(short *)(param_2 + 0x626);
    if (sVar1 != 0) {
      local_14 = 0;
      if (((uVar2 & 2) != 0) && (sVar1 < 0)) {
        local_14 = FUN_00407498((int)-sVar1);
      }
      if (local_14 != 0) {
        piVar4 = (int *)FUN_006359f2(local_14,0,&cXObject::RTTI_Type_Descriptor,
                                     &cXPerson::RTTI_Type_Descriptor,0);
        cVar3 = FUN_00422665(local_14 + 0xf4);
        if (cVar3 == '\0') {
          if ((*(int *)(local_14 + 0x134) - *(int *)(local_14 + 0x130)) / 0x24 + -1 < 2) {
            local_1c = 0;
          }
          else {
            local_1c = *(int *)(local_14 + 0x130) + 0x48;
          }
          if ((*(uint *)(local_1c + 0x1c) & 2) != 0) {
            if ((*(short *)(local_1c + 0x10) != 0) &&
               (iVar5 = FUN_00407498((int)*(short *)(local_1c + 0x10)), iVar5 != 0)) {
              FUN_0044822b(iVar5);
            }
            (**(code **)(**(int **)(param_1 + 0xcc) + 0x58))
                      (local_14 + 0xf4,*(undefined4 *)(local_14 + 0x110),local_14,1,1);
            piVar6 = (int *)(**(code **)(**(int **)(param_1 + 0xcc) + 0x2c))();
            piVar7 = (int *)(**(code **)(*piVar4 + 0x8c))();
            uVar8 = (**(code **)(*piVar7 + 0xb0))();
            (**(code **)(*piVar6 + 0xb8))(uVar8);
            (**(code **)(*piVar6 + 100))(1);
            (**(code **)(*piVar6 + 0xd4))(1);
            (**(code **)(*piVar6 + 0x54))(0);
            piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))(0);
            (**(code **)(*piVar4 + 0x54))();
            (**(code **)(*piVar6 + 0x50))(0);
          }
        }
      }
    }
  }
  return;
}

