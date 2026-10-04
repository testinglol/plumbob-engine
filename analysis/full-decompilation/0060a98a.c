
int __thiscall
FUN_0060a98a(int *param_1,int *param_2,int param_3,int param_4,int *param_5,char param_6)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined2 *puVar12;
  undefined2 local_30;
  int local_14;
  int local_10;
  undefined2 *local_c;
  int local_8;
  
  piVar2 = param_2;
  cVar3 = (char)param_5[2];
  if (cVar3 == '_') {
    iVar5 = 0;
  }
  else {
    iVar5 = param_2[7];
    iVar1 = param_2[8];
    if (((1 < *param_5) && (((cVar3 == -0x45 || (cVar3 == -0x43)) || (cVar3 == -0x41)))) &&
       (((cVar3 = *(char *)((int)param_5 + 9), cVar3 == -0x28 || (cVar3 == -0x27)) ||
        (cVar3 == -0x26)))) {
      *(char *)(param_5 + 3) = (char)param_5[3] + '\x03';
    }
    local_8 = 0;
    if (0 < *param_5) {
      do {
        iVar6 = FUN_006092f4(*(undefined1 *)((int)param_5 + local_8 + 8));
        iVar7 = FUN_0060931d(*(undefined1 *)((int)param_5 + local_8 + 8));
        if ((param_6 != '\0') && (local_8 == 0)) {
          uVar8 = (**(code **)(*piVar2 + 0xd0))();
          iVar9 = (**(code **)(*piVar2 + 0xcc))();
          puVar12 = (undefined2 *)(iVar9 + ((uVar8 >> 1) * param_4 + param_3) * 2);
          local_30 = puVar12[1];
          iVar9 = (**(code **)(*param_1 + 0x58))();
          local_14 = 0;
          if (0 < iVar9) {
            param_2 = (int *)param_4;
            do {
              if (-1 < (int)param_2) {
                if (piVar2[8] <= (int)param_2) break;
                local_10 = 0;
                iVar10 = param_3;
                local_c = puVar12;
                if (param_5[1] != -1 && -1 < param_5[1] + 1) {
                  do {
                    if (-1 < iVar10) {
                      if (piVar2[7] <= iVar10) break;
                      *local_c = (short)param_1[5];
                    }
                    local_10 = local_10 + 1;
                    iVar10 = iVar10 + 1;
                    local_c = local_c + 1;
                  } while (local_10 < param_5[1] + 1);
                }
              }
              local_14 = local_14 + 1;
              param_2 = (int *)((int)param_2 + 1);
              puVar12 = puVar12 + (uVar8 >> 1);
            } while (local_14 < iVar9);
          }
        }
        param_2 = (int *)0x0;
        if (0 < iVar6) {
          do {
            iVar9 = (int)*(char *)(local_8 + 0xb + (int)param_5) + (int)param_2 + param_3;
            if (((-1 < iVar9) && (iVar9 < iVar5)) && (local_c = (undefined2 *)0x0, 0 < iVar7)) {
              do {
                iVar10 = (int)*(char *)(local_8 + 0xe + (int)param_5) + (int)local_c + param_4;
                if (((-1 < iVar10) && (iVar10 < iVar1)) &&
                   (iVar11 = FUN_006094eb(*(undefined1 *)(local_8 + 8 + (int)param_5),param_2,
                                          local_c), iVar11 != 0)) {
                  uVar4 = local_30;
                  if (param_6 == '\0') {
                    uVar4 = (undefined2)param_1[5];
                  }
                  *(undefined2 *)(piVar2[0xd] + (piVar2[0xe] * iVar10 + iVar9) * 2) = uVar4;
                }
                local_c = (undefined2 *)((int)local_c + 1);
              } while ((int)local_c < iVar7);
            }
            param_2 = (int *)((int)param_2 + 1);
          } while ((int)param_2 < iVar6);
        }
        local_8 = local_8 + 1;
      } while (local_8 < *param_5);
    }
    cVar3 = (**(code **)(*param_1 + 0x28))(4);
    if (cVar3 != '\0') {
      iVar5 = (**(code **)(*param_1 + 0x58))();
      param_4 = iVar5 + -3 + param_4;
      if (((-1 < param_4) && (param_4 < piVar2[8])) &&
         (param_2 = (int *)0x0, param_5[1] != -1 && -1 < param_5[1] + 1)) {
        do {
          if ((-1 < param_3 + (int)param_2) && (param_3 + (int)param_2 < piVar2[7])) {
            *(short *)(piVar2[0xd] + (piVar2[0xe] * param_4 + (int)param_2 + param_3) * 2) =
                 (short)param_1[5];
          }
          param_2 = (int *)((int)param_2 + 1);
        } while ((int)param_2 < param_5[1] + 1);
      }
    }
    cVar3 = (**(code **)(*param_1 + 0x38))((int)(char)param_5[2]);
    iVar5 = param_5[1] + (uint)(cVar3 == '\0');
  }
  return iVar5;
}

