
undefined4 __thiscall FUN_0053a26b(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int *local_8;
  
  FUN_004e609e();
  cVar1 = FUN_004e6133();
  if (cVar1 == '\x01') {
    local_10 = 0;
    local_c = 0;
    FUN_004ba1dc(param_2,param_3,param_1[0x16],*(undefined4 *)(param_1[0x4b] + 0x60),&local_10,0);
  }
  else {
    cVar1 = (**(code **)(*param_2 + 0x20))(0x10);
    if (cVar1 != '\0') {
      FUN_004e609e();
      cVar1 = FUN_004e6133();
      if (cVar1 == '\0') {
        iVar2 = param_1[0x4b];
        local_38 = *(undefined4 *)(iVar2 + 0x14);
        local_34 = *(undefined4 *)(iVar2 + 0x18);
        local_30 = *(undefined4 *)(iVar2 + 0x1c);
        local_2c = *(undefined4 *)(iVar2 + 0x20);
        (**(code **)(*param_2 + 0x9c))(param_1[0x16],&local_38,param_3,0);
      }
      (**(code **)(*param_2 + 0x24))(0x10);
    }
  }
  if (((DAT_006f2a08 != 0) && (local_8 = *(int **)(DAT_006f2a08 + 0x88), local_8 != (int *)0x0)) &&
     (cVar1 = (**(code **)(*local_8 + 0x8c))(1), cVar1 != '\0')) {
    iVar2 = FUN_00401f6f();
    if (iVar2 == 0) {
      iVar2 = param_1[0x7f];
      local_10 = 0x71;
      local_c = 0x33;
    }
    else if (iVar2 == 1) {
      iVar2 = param_1[0x7e];
      local_10 = 0x40;
      local_c = 0x23;
    }
    else if (iVar2 == 2) {
      iVar2 = param_1[0x7d];
      local_10 = 7;
      local_c = 0x1e;
    }
    else {
      if (iVar2 == 3) {
        iVar2 = param_1[0x80];
        local_10 = 0xb7;
      }
      else {
        if (iVar2 != 4) {
          return 1;
        }
        iVar2 = param_1[0x81];
        local_10 = 0xa5;
      }
      local_c = 0x53;
    }
    if (iVar2 != 0) {
      local_38 = *(undefined4 *)(iVar2 + 0x14);
      local_34 = *(undefined4 *)(iVar2 + 0x18);
      local_30 = *(undefined4 *)(iVar2 + 0x1c);
      local_14 = param_3[1] + local_c;
      local_18 = *param_3 + local_10;
      local_2c = *(undefined4 *)(iVar2 + 0x20);
      local_28 = local_38;
      local_24 = local_34;
      local_20 = local_30;
      local_1c = local_2c;
      FUN_004ba5ac(&local_18);
      uVar3 = (**(code **)(*local_8 + 0xb0))();
      if ((uVar3 & 0xf8) == 0xf8) {
        cVar1 = (**(code **)(*param_2 + 0x20))(0x10);
        if (cVar1 != '\0') {
          (**(code **)(*param_2 + 0x9c))(iVar2,&local_38,&local_28,0);
          (**(code **)(*param_2 + 0x24))(0x10);
        }
      }
      else if ((uVar3 & 0xf8) != 0) {
        (*DAT_006f0674)(param_2,&local_28,iVar2,&local_38,param_2,&local_28,0xff - (uVar3 & 0xff));
        (**(code **)(*param_1 + 0x168))();
      }
    }
  }
  return 1;
}

