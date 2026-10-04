
undefined4 __thiscall
FUN_00422aee(int param_1,int *param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_4 == 0) {
    local_c = 0;
    local_14 = *param_2;
    local_10 = param_2[1];
    local_8 = 0;
    iVar6 = *(int *)(param_1 + 400);
    if (*(int *)(param_1 + 400) == 0) {
      iVar6 = param_1;
    }
    piVar4 = (int *)FUN_00422055(*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x1a4));
    local_10 = local_10 - piVar4[1];
    local_14 = local_14 - *piVar4;
    iVar1 = *(int *)(param_1 + 0x1a8);
    cVar3 = FUN_00422665(&local_14);
    if (cVar3 == '\0') {
      param_4 = 0;
      param_2 = (int *)0xffffffff;
      if (iVar6 != 0) {
        do {
          local_c = local_14;
          local_8 = local_10;
          piVar4 = (int *)FUN_00422055(*(undefined4 *)(iVar6 + 0x1a0),*(undefined4 *)(iVar6 + 0x1a4)
                                      );
          local_8 = local_8 + piVar4[1];
          local_c = local_c + *piVar4;
          cVar3 = FUN_004333c0(&local_c,*(int *)(iVar6 + 0x1a8) + (param_3 - iVar1),0,param_5);
          uVar2 = (uint)param_2;
          if (cVar3 == '\0') {
            if (((param_4 == 0) || (DAT_006e4a7c == 0x1e)) || (DAT_006e4a7c == 0x1f)) {
              param_4 = DAT_006e4a7c;
            }
            if (((DAT_006e4a7c != 1) && ((*(byte *)(param_1 + 0x9f) & 1) == 0)) &&
               ((uVar5 = *(uint *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x14) + 0xc) +
                                           (char)(local_8 >> 4) * 4) + (char)(local_c >> 4) * 4) &
                         0xff, uVar2 = uVar5, param_2 != (int *)0xffffffff &&
                ((uVar2 = (uint)param_2, param_2 != (int *)uVar5 && (param_4 == 0)))))) {
              param_4 = 0x11;
            }
          }
          param_2 = (int *)uVar2;
          iVar6 = *(int *)(iVar6 + 0x18c);
        } while (iVar6 != 0);
        if (param_4 != 0) {
          DAT_006e4a7c = param_4;
          return 0;
        }
      }
      return 1;
    }
    DAT_006e4a7c = 1;
  }
  else {
    DAT_006e4a7c = 0x10;
  }
  return 0;
}

