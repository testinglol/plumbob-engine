
void __thiscall FUN_0043c422(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_228 [272];
  undefined **local_118 [3];
  undefined1 local_10c [260];
  int local_8;
  
  iVar3 = 0;
  local_8 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2;
  FUN_0046f824(local_10c,0,0x104);
  local_118[0] = &PTR_FUN_006664e8;
  FUN_00412122(param_2,local_118);
  FUN_0043b76d(local_118);
  iVar2 = FUN_0046f973(param_1 + 0x140);
  if (iVar2 != 0) {
    iVar2 = FUN_0046f973(param_1 + 0x360);
    if (iVar2 == 0) {
      iVar3 = 1;
    }
    else {
      iVar2 = FUN_0046f973(param_1 + 0x580);
      if (iVar2 == 0) {
        iVar3 = 2;
      }
      else {
        iVar2 = FUN_0046f973(param_1 + 0x250);
        if (iVar2 == 0) {
          iVar3 = 3;
        }
        else if (((*(byte *)(DAT_006e486c + 0x66) & 1) == 0) ||
                (iVar2 = FUN_0046f973(param_1 + 0x690), iVar2 != 0)) {
          if (((*(byte *)(DAT_006e486c + 0x66) & 2) == 0) ||
             (iVar2 = FUN_0046f973(param_1 + 0x7a0), iVar2 != 0)) {
            if (((*(byte *)(DAT_006e486c + 0x66) & 4) == 0) ||
               (iVar2 = FUN_0046f973(param_1 + 0x8b0), iVar2 != 0)) {
              if (((*(byte *)(DAT_006e486c + 0x66) & 8) == 0) ||
                 (iVar2 = FUN_0046f973(param_1 + 0x9c0), iVar2 != 0)) {
                if (((*(byte *)(DAT_006e486c + 0x66) & 0x10) == 0) ||
                   (iVar2 = FUN_0046f973(param_1 + 0xad0), iVar2 != 0)) {
                  if (((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) ||
                     (iVar2 = FUN_0046f973(param_1 + 0xbe0), iVar2 != 0)) {
                    if (((*(byte *)(DAT_006e486c + 0x66) & 0x40) == 0) ||
                       (iVar2 = FUN_0046f973(param_1 + 0xcf0), iVar2 != 0)) {
                      if ((*(short *)(DAT_006e486c + 0x66) < 4) ||
                         (iVar2 = FUN_0046f973(param_1 + 0xf10), iVar2 != 0)) {
                        if ((*(short *)(DAT_006e486c + 0x66) < 4) ||
                           (iVar2 = FUN_0046f973(param_1 + 0x1020), iVar2 != 0)) {
                          if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) == 0) {
                            return;
                          }
                          iVar2 = FUN_0046f973(param_1 + 0xe00);
                          if (iVar2 != 0) {
                            return;
                          }
                          iVar3 = 0x800;
                        }
                        else {
                          iVar3 = 0x400;
                        }
                      }
                      else {
                        iVar3 = 0x200;
                      }
                    }
                    else {
                      iVar3 = 0x100;
                    }
                  }
                  else {
                    iVar3 = 0x80;
                  }
                }
                else {
                  iVar3 = 0x40;
                }
              }
              else {
                iVar3 = 0x20;
              }
            }
            else {
              iVar3 = 0x10;
            }
          }
          else {
            iVar3 = 8;
          }
        }
        else {
          iVar3 = 4;
        }
      }
    }
  }
  FUN_00405584(param_2);
  FUN_0043b76d(local_228);
  uVar1 = *(undefined1 *)(param_1 + 0x1241);
  if (iVar3 == 1) {
    *(undefined1 *)(param_1 + 0x1241) = 1;
  }
  FUN_0043b981(local_228,iVar3);
  if (iVar3 == 1) {
    *(undefined1 *)(param_1 + 0x1241) = uVar1;
  }
  if ((local_8 != *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2) &&
     (*(char *)(param_1 + 0x14) != '\0')) {
    FUN_0040766a(0xe0,0);
  }
  return;
}

