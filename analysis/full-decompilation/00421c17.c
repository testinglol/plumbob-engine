
void __thiscall FUN_00421c17(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  if (param_1[0x6b] == 0) {
    FUN_0042296a(param_2);
  }
  else {
    (**(code **)(*param_1 + 0x50))(1);
    (**(code **)(*(int *)param_1[0x6b] + 0x4c))(param_2);
    iVar2 = param_1[0x6b];
    if (*(short *)(*(int *)(iVar2 + 0x118) + 0x14) == 0) {
      iVar2 = (*(int *)(iVar2 + 0x134) - *(int *)(iVar2 + 0x130)) / 0x24 + -2;
      if (-1 < iVar2) {
        local_8 = (iVar2 * 9 + 9) * 4;
        do {
          iVar5 = param_1[0x6b];
          if ((iVar2 < 0) ||
             ((*(int *)(iVar5 + 0x134) - *(int *)(iVar5 + 0x130)) / 0x24 + -1 <= iVar2)) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(iVar5 + 0x130) + local_8;
          }
          if (iVar5 == 0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_00407498((int)*(short *)(iVar5 + 0x10));
          }
          if (((piVar4 != (int *)0x0) && (*(short *)(piVar4[0x46] + 0x14) == 0)) &&
             ((short)piVar4[0x1e] == 2)) {
            (**(code **)(*piVar4 + 0x4c))(param_2);
          }
          local_8 = local_8 + -0x24;
          iVar2 = iVar2 + -1;
        } while (-1 < iVar2);
      }
    }
    else {
      iVar2 = FUN_006359f2(iVar2,0,&cXObject::RTTI_Type_Descriptor,&cXMTObject::RTTI_Type_Descriptor
                           ,0);
      if (iVar2 != 0) {
        if (*(int *)(iVar2 + 400) != 0) {
          iVar2 = *(int *)(iVar2 + 400);
        }
        for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18c)) {
          iVar5 = (*(int *)(iVar2 + 0x134) - *(int *)(iVar2 + 0x130)) / 0x24 + -2;
          if (-1 < iVar5) {
            local_8 = (iVar5 * 9 + 9) * 4;
            if (iVar5 < 0) goto LAB_00421cd5;
            do {
              if (iVar5 < (*(int *)(iVar2 + 0x134) - *(int *)(iVar2 + 0x130)) / 0x24 + -1) {
                iVar3 = local_8 + *(int *)(iVar2 + 0x130);
              }
              else {
LAB_00421cd5:
                iVar3 = 0;
              }
              if (iVar3 == 0) {
                piVar4 = (int *)0x0;
              }
              else {
                piVar4 = (int *)FUN_00407498((int)*(short *)(iVar3 + 0x10));
              }
              if (((piVar4 != (int *)0x0) && (*(short *)(piVar4[0x46] + 0x14) == 0)) &&
                 ((short)piVar4[0x1e] == 2)) {
                (**(code **)(*piVar4 + 0x4c))(param_2);
              }
              local_8 = local_8 + -0x24;
              iVar5 = iVar5 + -1;
            } while (-1 < iVar5);
          }
        }
      }
    }
    (**(code **)(*param_1 + 0x88))();
    cVar1 = (**(code **)(*param_1 + 0x54))
                      (param_1 + 0x6d,param_1[0x6f],0,(int)*(short *)((int)param_1 + 0x1c6));
    if (cVar1 == '\0') {
      piVar4 = (int *)param_1[100];
      if ((int *)param_1[100] == (int *)0x0) {
        piVar4 = param_1;
      }
      while (iVar2 = FUN_006359f2(piVar4,0,&cXMTObject::RTTI_Type_Descriptor,
                                  &cXCursorObject::RTTI_Type_Descriptor,0), iVar2 != 0) {
        *(undefined2 *)(iVar2 + 0x1b0) = 0;
        piVar4 = *(int **)(iVar2 + 0x18c);
      }
    }
    else {
      (**(code **)(*param_1 + 0x58))
                (param_1 + 0x6d,param_1[0x6f],0,(int)*(short *)((int)param_1 + 0x1c6),1);
    }
  }
  return;
}

