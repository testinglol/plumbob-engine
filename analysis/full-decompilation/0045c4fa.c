
int __thiscall FUN_0045c4fa(int *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  int local_38;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar5 = *(int *)(param_2 + 0x48);
  local_8 = FUN_004818cc();
  if ((*(int *)(local_8 + 0x14) != 0) && (1 < *(short *)((int)param_1 + 0x60e))) {
    FUN_0046dfa0(1,0);
  }
  iVar3 = FUN_004670a4((short)param_1[0x21]);
  if (iVar3 != 0) {
    piVar8 = param_1 + 0x2b8;
    FUN_0042ede2(*piVar8,param_1[0x2b9]);
    cVar1 = FUN_00482558(piVar8);
    if (cVar1 != '\0') {
      iVar4 = FUN_004818d0();
      iVar3 = local_8;
      *(undefined2 *)((int)param_1 + 0x5d6) = *(undefined2 *)(iVar4 + 0xe);
      if (*(short *)(iVar4 + 0xc) != 0) {
        local_8 = 0;
        iVar5 = FUN_00407498((int)*(short *)(iVar4 + 0xc));
        if (iVar5 != 0) {
          FUN_00457da4();
          sVar2 = FUN_004561a0(0x1a);
          if (sVar2 != 0) {
            FUN_0043270d(param_1);
            if (local_38 == iVar5) {
              iVar5 = 1;
              goto LAB_0045c635;
            }
            if (*(short *)((int)param_1 + 0x60e) < 2) {
              FUN_00457da4();
              iVar3 = *param_1;
              uVar9 = 0;
              uVar6 = FUN_004561a0(0x1a);
              cVar1 = (**(code **)(iVar3 + 0x34))(iVar5,0,uVar6,uVar9);
              if (cVar1 != '\0') {
                iVar5 = 3;
                goto LAB_0045c635;
              }
            }
          }
        }
        *(undefined4 *)(param_2 + 0x88) = 5;
        iVar5 = local_8;
        goto LAB_0045c635;
      }
      if ((uint)(param_1[0x2b9] - *piVar8 >> 3) < 2) goto LAB_0045c633;
      iVar4 = *piVar8;
      iVar7 = param_1[0x2b9] - iVar4 >> 3;
      local_1c = *(int *)(iVar4 + -8 + iVar7 * 8);
      local_18 = *(int *)(iVar4 + -4 + iVar7 * 8);
      local_24 = *(int *)(iVar5 + 0xf4);
      local_20 = *(int *)(iVar5 + 0xf8);
      iVar7 = *(int *)(local_8 + 0x34);
      local_14 = local_1c;
      local_10 = local_18;
      if (iVar7 == -3) {
        iVar5 = param_1[0x2b9] - iVar4 >> 3;
        local_c = local_1c - *(int *)(iVar4 + -0x10 + iVar5 * 8);
        iVar5 = local_18 - *(int *)(iVar4 + -0xc + iVar5 * 8);
        local_8 = local_18;
        piVar8 = (int *)FUN_00422055(0,0);
        if ((iVar5 == piVar8[1]) && (local_c == *piVar8)) {
          iVar7 = (int)(short)param_1[0x13];
          goto LAB_0045c767;
        }
        local_10 = local_10 + iVar5;
        iVar5 = local_c;
      }
      else {
        if ((iVar7 == -1) || (iVar7 == -2)) {
          if ((char)*(uint *)(local_8 + 0x1c) == '\0') {
            if ((local_20 == local_18) && (local_24 == local_1c)) {
              iVar7 = (int)*(short *)(iVar5 + 0x4c);
            }
            else {
              iVar7 = FUN_00452129(&local_24);
            }
            if (*(int *)(iVar3 + 0x34) == -1) {
              iVar7 = (iVar7 + 4) % 8;
            }
          }
          else {
            local_14 = local_24;
            local_10 = local_20;
            if ((*(uint *)(local_8 + 0x1c) & 0x100) != 0) goto LAB_0045c77a;
            local_14 = local_1c;
            local_10 = local_18;
            iVar7 = FUN_00452129(&local_24);
            if (*(int *)(iVar3 + 0x34) == -1) {
              iVar7 = (iVar7 + 4) % 8;
            }
          }
        }
        else {
          iVar7 = *(short *)(iVar5 + 0x4c) + iVar7;
        }
LAB_0045c767:
        piVar8 = (int *)FUN_004222bd(iVar7);
        local_10 = local_10 + piVar8[1];
        iVar5 = *piVar8;
      }
      local_14 = local_14 + iVar5;
LAB_0045c77a:
      if ((local_10 == local_18) && (local_14 == local_1c)) {
        return 0;
      }
      FUN_0045f7c5(&local_14);
      return 2;
    }
  }
LAB_0045c633:
  iVar5 = 0;
LAB_0045c635:
  FUN_004819f6();
  return iVar5;
}

