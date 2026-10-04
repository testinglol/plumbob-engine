
int __thiscall
FUN_00609cb9(int *param_1,int *param_2,int param_3,int param_4,undefined4 param_5,char param_6,
            int *param_7)

{
  int *piVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined2 local_18;
  int local_10;
  
  piVar1 = param_2;
  iVar4 = FUN_00608a15(param_5);
  iVar5 = FUN_00608a37(param_5);
  if (param_6 != '\0') {
    uVar6 = (**(code **)(*param_2 + 0xd0))();
    iVar7 = (**(code **)(*param_2 + 0xcc))();
    param_2 = (int *)(iVar7 + ((uVar6 >> 1) * param_4 + param_3) * 2);
    local_18 = *(undefined2 *)((int)param_2 + 2);
    local_10 = (**(code **)(*param_1 + 0x58))();
    if (0 < local_10) {
      do {
        puVar9 = (undefined2 *)param_2;
        iVar7 = iVar4;
        if (0 < iVar4) {
          do {
            *puVar9 = (short)param_1[5];
            iVar7 = iVar7 + -1;
            puVar9 = puVar9 + 1;
          } while (iVar7 != 0);
        }
        local_10 = local_10 + -1;
        param_2 = (int *)((int)param_2 + (uVar6 >> 1) * 2);
      } while (local_10 != 0);
    }
  }
  local_10 = 0;
  iVar7 = param_4;
  if (0 < iVar5) {
    do {
      if (param_7 == (int *)0x0) {
LAB_00609d7a:
        if ((iVar7 < 0) || (piVar1[8] <= iVar7)) break;
        param_2 = (int *)0x0;
        iVar10 = param_3;
        if (0 < iVar4) {
          do {
            if (param_7 == (int *)0x0) {
LAB_00609db4:
              if (((-1 < iVar10) && (iVar10 < piVar1[7])) &&
                 (iVar8 = FUN_00608c05(param_5,param_2,local_10), iVar8 != 0)) {
                uVar3 = local_18;
                if (param_6 == '\0') {
                  uVar3 = (undefined2)param_1[5];
                }
                *(undefined2 *)(piVar1[0xd] + (piVar1[0xe] * iVar7 + iVar10) * 2) = uVar3;
                cVar2 = (**(code **)(*param_1 + 0x28))(0x10);
                if (((cVar2 != '\0') && (iVar8 = iVar7 + 1, iVar8 < piVar1[8])) &&
                   (*(undefined2 *)(piVar1[0xd] + (piVar1[0xe] * iVar8 + iVar10) * 2) = 0,
                   iVar10 + 1 < piVar1[7])) {
                  *(undefined2 *)(piVar1[0xd] + 2 + (piVar1[0xe] * iVar8 + iVar10) * 2) = 0;
                }
              }
            }
            else if (*param_7 <= iVar10) {
              if (iVar10 < param_7[2]) goto LAB_00609db4;
              break;
            }
            param_2 = (int *)((int)param_2 + 1);
            iVar10 = iVar10 + 1;
          } while ((int)param_2 < iVar4);
        }
      }
      else if (param_7[1] <= iVar7) {
        if (iVar7 < param_7[3]) goto LAB_00609d7a;
        break;
      }
      local_10 = local_10 + 1;
      iVar7 = iVar7 + 1;
    } while (local_10 < iVar5);
  }
  cVar2 = (**(code **)(*param_1 + 0x28))(4);
  if (((cVar2 != '\0') && (param_4 = **(int **)param_1[7] + -1 + param_4, -1 < param_4)) &&
     (((param_4 < piVar1[8] && (param_7 != (int *)0x0)) &&
      (((param_4 < param_7[1] || (param_7[3] <= param_4)) && (param_2 = (int *)0x0, 0 < iVar4))))))
  {
    do {
      if (*param_7 <= param_3) {
        if (param_7[2] <= param_3) {
          return iVar4;
        }
        if ((-1 < param_3) && (param_3 < piVar1[7])) {
          *(short *)(piVar1[0xd] + (piVar1[0xe] * param_4 + param_3) * 2) = (short)param_1[5];
        }
      }
      param_2 = (int *)((int)param_2 + 1);
      param_3 = param_3 + 1;
    } while ((int)param_2 < iVar4);
  }
  return iVar4;
}

