
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061d4b0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
                 int param_7,int param_8)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  
  iVar3 = param_2;
  if ((double)(param_3 - param_1) == _DAT_006669e8) {
    if ((double)(param_4 - param_2) != _DAT_006669e8) {
      iVar4 = param_2;
      if (param_4 <= param_2) {
        iVar4 = param_4;
      }
      param_2 = iVar4 * param_8;
      puVar5 = (undefined1 *)(param_2 + param_1 + param_7);
      do {
        while( true ) {
          iVar2 = iVar3;
          if (iVar3 <= param_4) {
            iVar2 = param_4;
          }
          if (iVar2 <= iVar4) {
            return;
          }
          if ((((-1 < param_1) && (param_1 < *(int *)(param_6 + 0x10))) && (-1 < iVar4)) &&
             (iVar4 < *(int *)(param_6 + 0x14))) break;
LAB_0061d5e4:
          param_2 = param_2 + param_8;
          iVar4 = iVar4 + 1;
          puVar5 = puVar5 + param_8;
        }
        if (*(int *)(param_6 + 0x18) != 8) {
          *(undefined4 *)(param_2 + param_1 * 4 + param_7) = param_5;
          goto LAB_0061d5e4;
        }
        *puVar5 = (undefined1)param_5;
        param_2 = param_2 + param_8;
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + param_8;
      } while( true );
    }
    if (((-1 < param_1) && (param_1 < *(int *)(param_6 + 0x10))) &&
       ((-1 < param_2 && (param_2 < *(int *)(param_6 + 0x14))))) {
      if (*(int *)(param_6 + 0x18) != 8) {
        *(undefined4 *)(param_7 + param_2 * param_8 + param_1 * 4) = param_5;
        return;
      }
      *(undefined1 *)(param_2 * param_8 + param_1 + param_7) = (undefined1)param_5;
      return;
    }
  }
  else {
    dVar1 = ABS((double)(param_4 - param_2) / (double)(param_3 - param_1));
    if (param_3 < param_1) {
      if (dVar1 <= _DAT_00667280) {
        if (param_3 < param_1) {
          do {
            if (((-1 < param_1) && (param_1 < *(int *)(param_6 + 0x10))) &&
               ((iVar3 = __ftol(), -1 < iVar3 && (iVar3 < *(int *)(param_6 + 0x14))))) {
              if (*(int *)(param_6 + 0x18) == 8) {
                *(undefined1 *)(iVar3 * param_8 + param_1 + param_7) = (undefined1)param_5;
              }
              else {
                *(undefined4 *)(param_7 + iVar3 * param_8 + param_1 * 4) = param_5;
              }
            }
            param_1 = param_1 + -1;
          } while (param_3 < param_1);
          return;
        }
        return;
      }
    }
    else if (dVar1 <= _DAT_00667280) {
      if (param_1 < param_3) {
        do {
          if ((((-1 < param_1) && (param_1 < *(int *)(param_6 + 0x10))) &&
              (iVar3 = __ftol(), -1 < iVar3)) && (iVar3 < *(int *)(param_6 + 0x14))) {
            if (*(int *)(param_6 + 0x18) == 8) {
              *(undefined1 *)(iVar3 * param_8 + param_1 + param_7) = (undefined1)param_5;
            }
            else {
              *(undefined4 *)(param_7 + iVar3 * param_8 + param_1 * 4) = param_5;
            }
          }
          param_1 = param_1 + 1;
        } while (param_1 < param_3);
        return;
      }
      return;
    }
    if (param_4 < param_2) {
      if ((_DAT_00667280 < dVar1) && (param_4 < param_2)) {
        iVar3 = param_2 * param_8;
        do {
          iVar4 = __ftol();
          if (((-1 < iVar4) && (iVar4 < *(int *)(param_6 + 0x10))) &&
             ((-1 < param_2 && (param_2 < *(int *)(param_6 + 0x14))))) {
            if (*(int *)(param_6 + 0x18) == 8) {
              *(undefined1 *)(iVar3 + iVar4 + param_7) = (undefined1)param_5;
            }
            else {
              *(undefined4 *)(iVar3 + iVar4 * 4 + param_7) = param_5;
            }
          }
          param_2 = param_2 + -1;
          iVar3 = iVar3 - param_8;
        } while (param_4 < param_2);
      }
    }
    else if ((_DAT_00667280 < dVar1) && (param_2 < param_4)) {
      iVar3 = param_2 * param_8;
      do {
        iVar4 = __ftol();
        if ((((-1 < iVar4) && (iVar4 < *(int *)(param_6 + 0x10))) && (-1 < param_2)) &&
           (param_2 < *(int *)(param_6 + 0x14))) {
          if (*(int *)(param_6 + 0x18) == 8) {
            *(undefined1 *)(iVar3 + iVar4 + param_7) = (undefined1)param_5;
          }
          else {
            *(undefined4 *)(iVar3 + iVar4 * 4 + param_7) = param_5;
          }
        }
        param_2 = param_2 + 1;
        iVar3 = iVar3 + param_8;
      } while (param_2 < param_4);
      return;
    }
  }
  return;
}

