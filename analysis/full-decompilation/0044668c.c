
void __thiscall FUN_0044668c(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int local_50;
  int local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int *local_24;
  int local_20;
  short local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int *local_c;
  char local_8;
  
  if (((param_2 != 0) && (*(char *)(param_1 + 0x11) != '\0')) && (*(int *)(param_1 + 200) != 0)) {
    local_8 = (*(uint *)(param_2 + 0x114) & 2) != 0;
    local_c = (int *)FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,
                                  &cXPerson::RTTI_Type_Descriptor,0);
    if (local_c != (int *)0x0) {
      if (local_8 != '\0') {
        FUN_0043270d(*(undefined4 *)(param_1 + 200));
        if (param_2 != local_50) {
          (**(code **)(**(int **)(param_1 + 200) + 0x50))(1);
        }
        cVar1 = FUN_00422665(param_2 + 0xf4);
        if (cVar1 == '\0') {
          if ((*(int *)(param_2 + 0x134) - *(int *)(param_2 + 0x130)) / 0x24 + -1 < 2) {
            local_10 = 0;
          }
          else {
            local_10 = *(int *)(param_2 + 0x130) + 0x48;
          }
          if ((*(uint *)(local_10 + 0x1c) & 2) != 0) {
            if ((*(short *)(local_10 + 0x10) != 0) &&
               (local_18 = FUN_00407498((int)*(short *)(local_10 + 0x10)), local_18 != 0)) {
              FUN_0044822b(local_18);
            }
            (**(code **)(**(int **)(param_1 + 200) + 0x58))
                      (param_2 + 0xf4,*(undefined4 *)(param_2 + 0x110),param_2,1,1);
            local_14 = (int *)(**(code **)(**(int **)(param_1 + 200) + 0x2c))();
            piVar2 = (int *)(**(code **)(*local_c + 0x8c))();
            uVar3 = (**(code **)(*piVar2 + 0xb0))();
            (**(code **)(*local_14 + 0xb8))(uVar3);
            (**(code **)(*local_14 + 100))(1);
            (**(code **)(*local_14 + 0xd4))(1);
            piVar2 = (int *)(**(code **)(*local_c + 0x2c))(0);
            (**(code **)(*piVar2 + 0x54))();
            (**(code **)(*local_14 + 0x50))(0);
          }
        }
      }
      iVar4 = FUN_00445724();
      if ((iVar4 == 0) && (*(int *)(param_1 + 200) != 0)) {
        (**(code **)(**(int **)(param_1 + 200) + 0x50))(1);
        piVar2 = (int *)(**(code **)(*local_c + 0x2c))(0);
        (**(code **)(*piVar2 + 0x54))();
      }
    }
    if ((((local_8 != '\0') && (local_c != (int *)0x0)) && (*(int *)(param_1 + 0xcc) != 0)) &&
       (local_1c = *(short *)((int)local_c + 0x626), local_1c != 0)) {
      local_20 = 0;
      if (local_1c < 0) {
        local_1c = -local_1c;
        local_20 = FUN_00407498((int)local_1c);
        (**(code **)(**(int **)(param_1 + 0xcc) + 0x50))(1);
      }
      if (local_20 != 0) {
        local_24 = (int *)FUN_006359f2(local_20,0,&cXObject::RTTI_Type_Descriptor,
                                       &cXPerson::RTTI_Type_Descriptor,0);
        cVar1 = FUN_00422665(local_20 + 0xf4);
        if (cVar1 == '\0') {
          if ((*(int *)(local_20 + 0x134) - *(int *)(local_20 + 0x130)) / 0x24 + -1 < 2) {
            local_28 = 0;
          }
          else {
            local_28 = *(int *)(local_20 + 0x130) + 0x48;
          }
          if ((*(uint *)(local_28 + 0x1c) & 2) != 0) {
            if ((*(short *)(local_28 + 0x10) != 0) &&
               (local_30 = FUN_00407498((int)*(short *)(local_28 + 0x10)), local_30 != 0)) {
              FUN_0044822b(local_30);
            }
            (**(code **)(**(int **)(param_1 + 0xcc) + 0x58))
                      (local_20 + 0xf4,*(undefined4 *)(local_20 + 0x110),local_20,1,1);
            local_2c = (int *)(**(code **)(**(int **)(param_1 + 0xcc) + 0x2c))();
            piVar2 = (int *)(**(code **)(*local_24 + 0x8c))();
            uVar3 = (**(code **)(*piVar2 + 0xb0))();
            (**(code **)(*local_2c + 0xb8))(uVar3);
            (**(code **)(*local_2c + 100))(1);
            (**(code **)(*local_2c + 0xd4))(1);
            (**(code **)(*local_2c + 0x54))(0);
            piVar2 = (int *)(**(code **)(*local_24 + 0x2c))(0);
            (**(code **)(*piVar2 + 0x54))();
            (**(code **)(*local_2c + 0x50))(0);
          }
        }
      }
    }
    iVar4 = FUN_00445724();
    if ((iVar4 == 0) && (*(int *)(param_1 + 0xcc) != 0)) {
      (**(code **)(**(int **)(param_1 + 0xcc) + 0x50))(1);
    }
    if (((((((*(ushort *)(DAT_006e486c + 0x66) & 0x40) != 0) && (local_8 == '\0')) &&
          (local_c != (int *)0x0)) &&
         ((local_34 = (int)*(short *)((int)local_c + 0x62e), 9 < local_34 &&
          ((local_38 = (int *)0x0, *(int *)(param_1 + 0xdc) != *(int *)(param_1 + 0xe0) ||
           (FUN_00446396(), *(int *)(param_1 + 0xdc) != *(int *)(param_1 + 0xe0))))))) &&
        (local_38 = *(int **)(*(int *)(param_1 + 0xe0) + -4), local_38 != (int *)0x0)) &&
       (cVar1 = FUN_00422665(param_2 + 0xf4), cVar1 == '\0')) {
      if ((*(int *)(param_2 + 0x134) - *(int *)(param_2 + 0x130)) / 0x24 + -1 < 2) {
        local_3c = 0;
      }
      else {
        local_3c = *(int *)(param_2 + 0x130) + 0x48;
      }
      if ((*(uint *)(local_3c + 0x1c) & 2) != 0) {
        if ((*(short *)(local_3c + 0x10) != 0) &&
           (iVar4 = FUN_00407498((int)*(short *)(local_3c + 0x10)), iVar4 != 0)) {
          FUN_0044822b(iVar4);
        }
        (**(code **)(*local_38 + 0x58))(param_2 + 0xf4,*(undefined4 *)(param_2 + 0x110),param_2,1,1)
        ;
        piVar2 = (int *)(**(code **)(*local_38 + 0x2c))();
        piVar5 = (int *)(**(code **)(*local_c + 0x8c))();
        uVar3 = (**(code **)(*piVar5 + 0xb0))();
        (**(code **)(*piVar2 + 0xb8))(uVar3);
        (**(code **)(*piVar2 + 100))(1);
        (**(code **)(*piVar2 + 0xd4))(1);
        piVar5 = (int *)(**(code **)(*local_c + 0x2c))(0);
        (**(code **)(*piVar5 + 0x54))();
        (**(code **)(*piVar2 + 0x50))(0);
        FUN_0044845a(&local_38);
        *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + -4;
      }
    }
  }
  return;
}

