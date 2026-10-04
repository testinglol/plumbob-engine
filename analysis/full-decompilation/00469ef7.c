
int __thiscall FUN_00469ef7(int *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  tagRECT *ptVar5;
  int *piVar6;
  int *piVar7;
  RECT *pRVar8;
  int local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  RECT local_60;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c [5];
  int *local_28;
  int *local_24;
  int *local_20;
  tagRECT local_1c;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  local_20 = param_1;
  local_24 = (int *)FUN_00469872(param_2);
  iVar3 = 0;
  if (local_24 != (int *)0x0) {
    piVar6 = (int *)(param_1[3] + local_24[1] * 0x14);
    piVar7 = local_3c;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar7 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar7 = piVar7 + 1;
    }
    local_1c.left = local_3c[0];
    local_c = 0;
    local_1c.right = local_3c[0] + 1;
    local_1c.top = local_3c[1] + -1;
    local_1c.bottom = local_3c[1];
    do {
      local_28 = (int *)FUN_004697dd(&local_1c);
      if ((local_28 == (int *)0x0) || (local_28[4] != 0x7fffffff)) {
        iVar3 = FUN_00469792(&local_1c);
        piVar6 = local_20;
        if (iVar3 == -1) {
          ptVar5 = &local_1c;
          pRVar8 = &local_60;
          for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
            pRVar8->left = ptVar5->left;
            ptVar5 = (tagRECT *)&ptVar5->top;
            pRVar8 = (RECT *)&pRVar8->top;
          }
          IsRectEmpty(&local_60);
          piVar6 = local_20;
          cVar1 = FUN_00469c16(&local_60);
          if (cVar1 == '\0') {
            FUN_00469c16(&local_60);
          }
          else {
            if (local_28 == (int *)0x0) {
              local_50 = *(int *)(*piVar6 + 0x2c);
            }
            else {
              local_50 = local_28[4];
            }
            FUN_0046ad0a(&local_60);
            iVar3 = (piVar6[4] - piVar6[3]) / 0x14 + -1;
          }
        }
        piVar7 = piVar6 + 0xf;
        local_7c = *(undefined4 *)(piVar6[3] + 0x10 + iVar3 * 0x14);
        local_8c = *local_24;
        local_84 = 0xffffffff;
        local_80 = 0xffffffff;
        for (piVar2 = (int *)*piVar7; local_88 = iVar3, piVar2 != (int *)piVar6[0x10];
            piVar2 = piVar2 + 0xb) {
          if ((*piVar2 == local_8c) && (piVar2[1] == iVar3)) {
            piVar2 = (int *)(((int)piVar2 - *piVar7) / 0x2c);
            if (piVar2 != (int *)0xffffffff) goto LAB_0046a073;
            break;
          }
        }
        FUN_0046ad3a(&local_8c);
        piVar2 = (int *)((piVar6[0x10] - *piVar7) / 0x2c + -1);
        local_24 = (int *)FUN_00469872(param_2);
LAB_0046a073:
        piVar6 = (int *)(piVar6[3] + *(int *)((int)piVar2 * 0x2c + 4 + *piVar7) * 0x14);
        local_4c = *piVar6;
        local_48 = piVar6[1];
        local_44 = piVar6[2];
        local_40 = piVar6[3];
        if (piVar2 != (int *)0xffffffff) {
          local_28 = piVar2;
          FUN_0040555d(&local_28);
          local_24[2] = local_24[2] + 1;
        }
      }
      else {
        local_4c = *local_28;
        local_48 = local_28[1];
        local_44 = local_28[2];
        local_40 = local_28[3];
      }
      iVar3 = local_8 / 4;
      iVar4 = local_8 % 4;
      if (iVar4 == 0) {
        if ((local_3c[2] < local_1c.right) || (local_3c[2] <= local_44)) {
          iVar4 = local_3c[2] - local_1c.left;
          iVar3 = 1;
          goto LAB_0046a14f;
        }
        iVar3 = local_44 - local_1c.left;
LAB_0046a146:
        iVar4 = 0;
LAB_0046a11f:
        iVar3 = OffsetRect(&local_1c,iVar3,iVar4);
      }
      else {
        if (iVar4 == 1) {
          if ((local_1c.bottom <= local_3c[3]) && (local_40 < local_3c[3])) {
            iVar4 = local_40 - local_1c.top;
LAB_0046a11d:
            iVar3 = 0;
            goto LAB_0046a11f;
          }
          iVar3 = local_3c[3] - local_1c.top;
          iVar4 = -1;
        }
        else if (iVar4 == 2) {
          if ((local_3c[0] <= local_1c.left) && (local_3c[0] < local_4c)) {
            iVar3 = (local_4c - local_1c.left) + -1;
            goto LAB_0046a146;
          }
          iVar3 = -1;
          iVar4 = (local_3c[0] - local_1c.left) + -1;
        }
        else {
          if (iVar4 != 3) goto LAB_0046a15c;
          if ((local_3c[1] <= local_1c.top) && (local_3c[1] < local_48)) {
            iVar4 = (local_48 - local_1c.top) + -1;
            goto LAB_0046a11d;
          }
          iVar3 = (local_3c[1] - local_1c.top) + -1;
          iVar4 = 1;
        }
LAB_0046a14f:
        iVar3 = OffsetRect(&local_1c,iVar4,iVar3);
        local_8 = local_8 + 1;
      }
LAB_0046a15c:
    } while (local_8 < 4);
  }
  return iVar3;
}

