
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005fb012(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  cVar2 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar2 == '\0') {
LAB_005fb1f6:
    uVar4 = 1;
  }
  else {
    cVar2 = (**(code **)(*DAT_006fed70 + 0x94))();
    if (cVar2 == '\0') {
      *(undefined1 *)(param_1 + 0x1a0) = 0;
      local_14 = local_14 & 0xfffdffef | 0x40;
      if (param_2 != (undefined4 *)0x0) {
        param_2[1] = param_2[1] & 0xfffdffef | 0x40;
      }
    }
    else if (param_2 == (undefined4 *)0x0) {
      local_10 = *(undefined4 *)(param_1 + 0xa4);
      local_8 = param_1 + 0xa8;
      local_18 = 0x14;
      local_c = 0;
      if (*(int *)(param_1 + 0x38) < 10) {
        local_14 = *(uint *)(param_1 + 200) & 0xfffffffb | 0x20018;
      }
      else {
        local_14 = *(uint *)(param_1 + 200) & 0xfffffff7 | 0x20010;
      }
      iVar3 = (**(code **)(*DAT_006fed6c + 0xc))
                        (DAT_006fed6c,&local_18,(undefined4 *)(param_1 + 0x80),0);
      if (iVar3 == 0) {
        _DAT_006fed64 = _DAT_006fed64 + 1;
        puVar1 = *(undefined4 **)(param_1 + 0x80);
        iVar3 = (**(code **)*puVar1)(puVar1,&DAT_00677238,(undefined4 *)(param_1 + 0x178));
        if (iVar3 == 0) {
          if (*(char *)(param_1 + 0x1b8) != '\0') {
            piVar5 = *(int **)(param_1 + 0x178);
            goto LAB_005fb1b3;
          }
          goto LAB_005fb1bd;
        }
      }
      *(undefined1 *)(param_1 + 0x1a0) = 0;
      local_14 = local_14 & 0xfffdffef | 0x40;
      param_2 = &local_18;
    }
    else {
      if (*(int *)(param_1 + 0x38) < 10) {
        param_2[1] = param_2[1] & 0xfffffffb | 8;
      }
      else {
        param_2[1] = param_2[1] & 0xfffffff7;
      }
      param_2[1] = param_2[1] & 0xffffffbf | 0x20010;
      iVar3 = (**(code **)(*DAT_006fed6c + 0xc))
                        (DAT_006fed6c,param_2,(undefined4 *)(param_1 + 0x80),0);
      if (iVar3 == 0) {
        _DAT_006fed60 = _DAT_006fed60 + 1;
        puVar1 = *(undefined4 **)(param_1 + 0x80);
        iVar3 = (**(code **)*puVar1)(puVar1,&DAT_00677238,param_1 + 0x178);
        if (iVar3 == 0) {
          if (*(char *)(param_1 + 0x1b8) != '\0') {
            piVar5 = *(int **)(param_1 + 0x178);
LAB_005fb1b3:
            (**(code **)(*piVar5 + 0x48))(piVar5,1,0);
          }
LAB_005fb1bd:
          *(undefined1 *)(param_1 + 0x1a0) = 1;
          (**(code **)(*(int *)(param_1 + 0x174) + 0xec))(*(undefined4 *)(param_1 + 0x198));
          (**(code **)(*(int *)(param_1 + 0x174) + 0xf4))(*(undefined4 *)(param_1 + 0x19c));
          goto LAB_005fb1f6;
        }
        *(undefined1 *)(param_1 + 0x1a0) = 0;
        param_2[1] = param_2[1] & 0xfffdffef | 0x40;
      }
      else {
        *(undefined1 *)(param_1 + 0x1a0) = 0;
        param_2[1] = param_2[1] & 0xfffdffef;
      }
    }
    uVar4 = FUN_005f92a4(param_2);
  }
  return uVar4;
}

