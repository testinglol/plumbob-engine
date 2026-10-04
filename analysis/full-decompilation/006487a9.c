
bool FUN_006487a9(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  if (DAT_006de188 != 0) {
    iVar2 = param_1[5];
    if ((iVar2 != DAT_006de218) || (iVar2 != DAT_006de228)) {
      if (DAT_00703d90 == 0) {
        FUN_00648955(1,1,iVar2,4,1,0,0,2,0,0,0);
        FUN_00648955(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_00703e30 != 0) {
          uVar4 = 0;
          uVar3 = 0;
          uVar5 = DAT_00703e36;
        }
        else {
          uVar4 = DAT_00703e34;
          uVar3 = DAT_00703e36;
          uVar5 = 0;
        }
        FUN_00648955(1,DAT_00703e30 == 0,iVar2,DAT_00703e32,uVar3,uVar4,uVar5,DAT_00703e38,
                     DAT_00703e3a,DAT_00703e3c,DAT_00703e3e);
        if (DAT_00703ddc != 0) {
          uVar4 = 0;
          uVar3 = 0;
          iVar2 = param_1[5];
          uVar5 = DAT_00703de2;
        }
        else {
          iVar2 = param_1[5];
          uVar4 = DAT_00703de0;
          uVar3 = DAT_00703de2;
          uVar5 = 0;
        }
        FUN_00648955(0,DAT_00703ddc == 0,iVar2,DAT_00703dde,uVar3,uVar4,uVar5,DAT_00703de4,
                     DAT_00703de6,DAT_00703de8,DAT_00703dea);
      }
    }
    iVar2 = param_1[7];
    if (DAT_006de21c < DAT_006de22c) {
      if ((DAT_006de21c <= iVar2) && (iVar2 <= DAT_006de22c)) {
        if ((DAT_006de21c < iVar2) && (iVar2 < DAT_006de22c)) {
          return true;
        }
LAB_00648921:
        iVar1 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar2 == DAT_006de21c) {
          return DAT_006de220 <= iVar1;
        }
        return iVar1 < DAT_006de230;
      }
    }
    else {
      if (iVar2 < DAT_006de22c) {
        return true;
      }
      if (DAT_006de21c < iVar2) {
        return true;
      }
      if ((iVar2 <= DAT_006de22c) || (DAT_006de21c <= iVar2)) goto LAB_00648921;
    }
  }
  return false;
}

