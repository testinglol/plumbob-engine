
void __thiscall FUN_005eb881(int *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  tagPOINT local_10;
  int local_8;
  
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  *(undefined1 *)(param_1 + 0x53) = 1;
  *(undefined1 *)(param_1 + 0x55) = 0;
  *(bool *)((int)param_1 + 0x14e) = param_4 != 0;
  *(undefined1 *)((int)param_1 + 0x14d) = 1;
  param_1[0x60] = param_5;
  (**(code **)(*param_1 + 0x1b4))();
  (**(code **)(*param_1 + 0x90))(1,1);
  piVar5 = (int *)FUN_004b46a0();
  iVar8 = piVar5[0x21];
  iVar1 = piVar5[0x22];
  iVar2 = piVar5[0x1f];
  iVar3 = piVar5[0x20];
  iVar6 = param_1[0x4b] - param_1[0x4d];
  iVar7 = param_1[0x4c] - param_1[0x4e];
  param_1[0x4f] = iVar6;
  param_1[0x50] = iVar7;
  if (iVar6 < 0) {
    param_1[0x4f] = 0;
LAB_005eb94e:
    *(undefined1 *)(param_1 + 0x55) = 1;
  }
  else if (iVar8 - iVar2 <= iVar6 + param_1[0x51]) {
    param_1[0x4f] = (iVar8 - iVar2) - param_1[0x51];
    goto LAB_005eb94e;
  }
  if (iVar7 < 0) {
    param_1[0x50] = 0;
  }
  else {
    if (param_1[0x52] + iVar7 < iVar1 - iVar3) goto LAB_005eb97f;
    param_1[0x50] = (iVar1 - iVar3) - param_1[0x52];
  }
  *(undefined1 *)(param_1 + 0x55) = 1;
LAB_005eb97f:
  if ((char)param_1[0x55] != '\0') {
    local_10.x = param_1[0x4d] + param_1[0x4f];
    param_1[0x4b] = local_10.x;
    local_10.y = param_1[0x4e] + param_1[0x50];
    param_1[0x4c] = local_10.y;
    ClientToScreen(DAT_006fe8cc,&local_10);
    SetCursorPos(local_10.x,local_10.y);
  }
  (**(code **)(*param_1 + 0x60))
            (param_1[0x4f],param_1[0x50],param_1[0x51] + param_1[0x4f],param_1[0x52] + param_1[0x50]
            );
  param_3 = 0;
  if ((param_1[0x65] - param_1[100]) / 0x28 != 0) {
    param_2 = 0;
    do {
      iVar8 = param_2 + param_1[100];
      piVar4 = *(int **)(iVar8 + 0xc);
      if (piVar4 != (int *)0x0) {
        local_10.y = *(int *)(iVar8 + 0x18) + param_1[0x4f];
        local_8 = *(int *)(iVar8 + 0x1c) + param_1[0x50];
        (**(code **)(*piVar4 + 0x60))
                  (local_10.y,local_8,(piVar4[0x21] - piVar4[0x1f]) + local_10.y,
                   (piVar4[0x22] - piVar4[0x20]) + local_8);
        if ((char)piVar4[0x5a] != *(char *)(iVar8 + 0x10)) {
          *(char *)(piVar4 + 0x5a) = *(char *)(iVar8 + 0x10);
          (**(code **)(*piVar4 + 0x168))();
        }
        FUN_005ddfdc(1);
        (**(code **)(*piVar5 + 0x20))(piVar4);
      }
      param_3 = param_3 + 1;
      param_2 = param_2 + 0x28;
    } while (param_3 < (uint)((param_1[0x65] - param_1[100]) / 0x28));
  }
  param_1[0x35] = -1;
  param_4 = 0;
  param_5 = 0;
  FUN_005d9928(&param_4,&param_5);
  param_5 = param_5 - param_1[0x50];
  param_4 = param_4 - param_1[0x4f];
  (**(code **)(*param_1 + 0xfc))(param_4,param_5,0);
  return;
}

