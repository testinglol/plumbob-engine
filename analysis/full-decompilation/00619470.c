
void FUN_00619470(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = param_7;
  local_10 = 0;
  do {
    local_18 = 0;
    if (0 < param_6) {
      local_14 = 0;
      do {
        param_7 = 0;
        if (0 < param_5) {
          do {
            local_c = 0;
            if (0 < iVar1) {
              do {
                iVar3 = 0;
                do {
                  iVar3 = iVar3 + 1;
                } while (iVar3 < iVar1);
                local_c = local_c + 1;
              } while (local_c < iVar1);
            }
            uVar2 = __ftol();
            iVar3 = param_7 * 4;
            param_7 = param_7 + 1;
            *(undefined1 *)(local_14 + iVar3 + local_10 + param_1) = uVar2;
          } while (param_7 < param_5);
        }
        local_14 = local_14 + param_2;
        local_18 = local_18 + 1;
      } while (local_18 < param_6);
    }
    local_10 = local_10 + 1;
  } while (local_10 < 4);
  return;
}

