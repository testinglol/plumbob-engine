
void __thiscall FUN_0043143a(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  int *local_c;
  char *local_8;
  
  uVar8 = param_3;
  local_14 = 0;
  FUN_00464973(&local_14,1);
  local_18 = 0;
  FUN_00464973(&local_18,1);
  piVar7 = (int *)(param_1 + 8);
  FUN_00464a4e(piVar7,1);
  piVar9 = (int *)(param_1 + 4);
  FUN_00464a4e(piVar9,1);
  local_c = (int *)(param_1 + 0x1c);
  FUN_00464a4e(local_c,1);
  local_10 = uVar8 & 0xff;
  FUN_00464a4e(&local_10,1);
  if ((*(int *)(param_2 + 0xc) != 0) || (cVar2 = FUN_004313ae(*piVar7,*piVar9), cVar2 != '\0')) {
    local_8 = (char *)**(undefined4 **)(param_1 + 0xc);
    pcVar5 = (char *)((*(undefined4 **)(param_1 + 0xc))[*piVar7 + -1] + *local_c * *piVar9);
    if (local_10 == 0) {
      FUN_00464895(local_8,(int)pcVar5 - (int)local_8);
    }
    else if (*(int *)(param_2 + 0xc) == 1) {
      for (; local_8 < pcVar5; local_8 = local_8 + (int)piVar7) {
        pcVar3 = local_8;
        if (local_8 < pcVar5) {
          do {
            pcVar6 = pcVar3 + 1;
            local_c = (int *)0x1;
            if (pcVar6 < pcVar5) {
              do {
                if (*pcVar6 != *pcVar3) break;
                local_c = (int *)((int)local_c + 1);
                pcVar6 = pcVar6 + 1;
              } while (pcVar6 < pcVar5);
              if (7 < (int)local_c) break;
            }
            pcVar3 = pcVar3 + (int)local_c;
          } while (pcVar3 < pcVar5);
          if (pcVar3 == local_8) goto LAB_00431545;
          piVar7 = (int *)(pcVar3 + -(int)local_8);
          bVar1 = false;
        }
        else {
LAB_00431545:
          bVar1 = true;
          piVar7 = local_c;
        }
        if (0x7fff < (int)piVar7) {
          piVar7 = (int *)0x7fff;
        }
        local_1c = -(uint)bVar1 & 0xffff8000 | (uint)piVar7;
        FUN_00464973(&local_1c,1);
        piVar9 = piVar7;
        if (bVar1) {
          piVar9 = (int *)0x1;
        }
        FUN_00464895(local_8,piVar9);
        if ((*(byte *)(param_2 + 8) & 1) != 0) {
          param_3._3_1_ = 0;
          FUN_00464895((int)&param_3 + 3,1);
        }
      }
    }
    else {
      for (; local_8 < pcVar5; local_8 = local_8 + uVar8) {
        FUN_00464973(&local_c,1);
        pcVar3 = local_8;
        uVar8 = (uint)local_c & 0x7fff;
        if (((uint)local_c >> 0xf & 1) == 0) {
          FUN_00464895(local_8,uVar8);
        }
        else {
          FUN_00464895(local_8,1);
          iVar4 = 1;
          if (1 < uVar8) {
            do {
              pcVar3[iVar4] = *pcVar3;
              iVar4 = iVar4 + 1;
            } while (iVar4 < (int)uVar8);
          }
        }
        if ((*(byte *)(param_2 + 8) & 1) != 0) {
          FUN_00464895((int)&param_3 + 3,1);
        }
      }
    }
  }
  return;
}

