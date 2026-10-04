
undefined4 __thiscall FUN_004d503b(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if ((char)param_1[0x24] == '\0') {
LAB_004d510c:
    uVar3 = 0;
  }
  else {
    if (param_2 == 0x12) {
      if ((char)param_1[9] == '\0') {
        (**(code **)(*param_1 + 0x38))();
        *(undefined1 *)(param_1 + 9) = 1;
        FUN_004d555c();
        FUN_004d4d42(0x1b);
        (**(code **)(*param_1 + 8))(param_1[10],param_1[0xb],0);
      }
    }
    else {
      if (((((param_3 & 1) != 0) || ((param_3 >> 1 & 1) != 0)) || (param_1[1] == 1)) ||
         (((param_2 != 0x25 && (param_2 != 0x26)) && ((param_2 != 0x27 && (param_2 != 0x28))))))
      goto LAB_004d510c;
      param_3 = 0;
      FUN_0051eaec();
      iVar1 = *(int *)(*(int *)(DAT_006e486c + 4) + 0x58);
      iVar5 = iVar1;
      iVar2 = param_3;
      if ((param_2 != 0x25) && (iVar5 = iVar4, iVar2 = iVar1 >> 1, param_2 != 0x26)) {
        if (param_2 == 0x27) {
          iVar5 = -iVar1;
          iVar2 = param_3;
        }
        else {
          iVar2 = param_3;
          if (param_2 == 0x28) {
            iVar2 = -(iVar1 >> 1);
          }
        }
      }
      param_3 = iVar2;
      *(undefined1 *)((int)param_1 + 0x92) = 1;
      FUN_004a7a9c(iVar5,param_3);
    }
    uVar3 = 1;
  }
  return uVar3;
}

