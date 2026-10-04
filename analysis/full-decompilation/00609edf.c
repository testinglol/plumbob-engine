
int __thiscall
FUN_00609edf(int param_1,int *param_2,int param_3,int param_4,byte *param_5,uint param_6,
            int *param_7,int param_8,int param_9)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_18;
  undefined4 local_14;
  byte *local_10;
  uint local_c;
  
  bVar1 = false;
  if (*(char *)(param_1 + 0x20) == '\0') {
    cVar3 = (**(code **)(*param_2 + 0x20))(0x40);
    if (cVar3 == '\0') {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x20) = 1;
    bVar1 = true;
  }
  iVar6 = 0;
  local_c = 0;
  local_10 = param_5;
  local_18 = 0;
  if (param_6 != 0) {
    do {
      local_14 = 0;
      if ((param_8 <= (int)local_10 - (int)param_5) && ((int)local_10 - (int)param_5 < param_9)) {
        local_14 = 1;
      }
      uVar5 = (uint)*local_10;
      if (uVar5 == 0) break;
      if (local_c == 0) {
        iVar4 = FUN_00608ca3(uVar5);
        uVar2 = uVar5;
        if ((iVar4 == 0) && (uVar2 = local_c, uVar5 != 10)) {
          if ((param_7 == (int *)0x0) ||
             ((((iVar4 = FUN_00608a15(uVar5), iVar4 + iVar6 + param_3 <= param_7[2] &&
                (iVar4 = FUN_00608a37(uVar5), iVar4 + param_4 <= param_7[3])) &&
               (*param_7 <= param_3 + iVar6)) && (param_7[1] <= param_4)))) {
            FUN_00609cb9(param_2,param_3 + iVar6,param_4,uVar5,local_14,param_7);
          }
          iVar4 = FUN_00608a15(uVar5);
          iVar6 = iVar6 + iVar4;
        }
      }
      else {
        uVar5 = local_c << 8 | uVar5;
        if ((param_7 == (int *)0x0) ||
           (((iVar4 = FUN_00608a15(uVar5), iVar4 + iVar6 + param_3 <= param_7[2] &&
             (iVar4 = FUN_00608a37(uVar5), iVar4 + param_4 <= param_7[3])) &&
            ((*param_7 <= param_3 + iVar6 && (param_7[1] <= param_4)))))) {
          FUN_00609cb9(param_2,param_3 + iVar6,param_4,uVar5,local_14,param_7);
        }
        iVar4 = FUN_00608a15(uVar5);
        iVar6 = iVar6 + iVar4;
        local_c = 0;
        uVar2 = local_c;
      }
      local_c = uVar2;
      local_18 = local_18 + 1;
      local_10 = local_10 + 1;
    } while (local_18 < param_6);
  }
  if (bVar1) {
    (**(code **)(*param_2 + 0x24))(0x40);
    *(undefined1 *)(param_1 + 0x20) = 0;
  }
  return iVar6;
}

