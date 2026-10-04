
undefined4 __thiscall FUN_005dc8b5(int *param_1,int *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  switch(*param_2 + -1) {
  case 0:
    uVar2 = (**(code **)(*param_1 + 0x28))(param_2[1]);
    break;
  default:
    uVar2 = 0;
    break;
  case 2:
    uVar2 = (**(code **)(*param_1 + 300))(param_2[1],param_2[2]);
    break;
  case 3:
    cVar1 = (**(code **)(*DAT_006fe8f8 + 8))(0x11);
    if (cVar1 != '\0') {
      cVar1 = (char)param_2[1] + '@';
      if (cVar1 == s_XCVZYAQScaught_exception_in_chil_006d7448[0]) {
        uVar2 = (**(code **)(*param_1 + 0x144))();
        return uVar2;
      }
      if (cVar1 == s_XCVZYAQScaught_exception_in_chil_006d7448[1]) {
        uVar2 = (**(code **)(*param_1 + 0x140))();
        return uVar2;
      }
      if (cVar1 == s_XCVZYAQScaught_exception_in_chil_006d7448[2]) {
        uVar2 = (**(code **)(*param_1 + 0x148))();
        return uVar2;
      }
      if (cVar1 == s_XCVZYAQScaught_exception_in_chil_006d7448[3]) {
        uVar2 = (**(code **)(*param_1 + 0x14c))();
        return uVar2;
      }
      if (cVar1 == s_XCVZYAQScaught_exception_in_chil_006d7448[4]) {
        uVar2 = (**(code **)(*param_1 + 0x150))();
        return uVar2;
      }
      if (cVar1 == s_XCVZYAQScaught_exception_in_chil_006d7448[5]) {
        uVar2 = (**(code **)(*param_1 + 0x154))();
        return uVar2;
      }
      if (cVar1 == s_XCVZYAQScaught_exception_in_chil_006d7448[6]) {
        uVar2 = (**(code **)(*param_1 + 0x15c))();
        return uVar2;
      }
      if (cVar1 == s_XCVZYAQScaught_exception_in_chil_006d7448[7]) {
        uVar2 = (**(code **)(*param_1 + 0x158))();
        return uVar2;
      }
    }
    uVar2 = (**(code **)(*param_1 + 0xd8))((char)param_2[1]);
    break;
  case 4:
    uVar2 = (**(code **)(*param_1 + 0xdc))(param_2[1],param_2[2]);
    break;
  case 5:
    uVar2 = (**(code **)(*param_1 + 0xe0))(param_2[1],param_2[2]);
    break;
  case 6:
    (**(code **)(*param_1 + 0x11c))(param_2[1],param_2[2],param_2[3]);
    uVar2 = (**(code **)(*param_1 + 0xe4))(param_2[1],param_2[2],param_2[3]);
    break;
  case 7:
    uVar2 = (**(code **)(*param_1 + 0xe8))(param_2[1],param_2[2],param_2[3]);
    break;
  case 8:
    uVar2 = (**(code **)(*param_1 + 0xec))(param_2[1],param_2[2],param_2[3]);
    break;
  case 9:
    uVar2 = (**(code **)(*param_1 + 0xf0))(param_2[1],param_2[2],param_2[3]);
    break;
  case 10:
    (**(code **)(*param_1 + 0x124))(param_2[1],param_2[2],param_2[3]);
    uVar2 = (**(code **)(*param_1 + 0xf4))(param_2[1],param_2[2],param_2[3]);
    break;
  case 0xb:
    uVar2 = (**(code **)(*param_1 + 0xf8))(param_2[1],param_2[2],param_2[3]);
    break;
  case 0xc:
    (**(code **)(*param_1 + 0x120))(param_2[1],param_2[2],param_2[3]);
    uVar2 = (**(code **)(*param_1 + 0xfc))(param_2[1],param_2[2],param_2[3]);
    break;
  case 0xd:
    uVar2 = (**(code **)(*param_1 + 0x104))(param_2[1],param_2[2],param_2[3]);
    break;
  case 0xe:
    uVar2 = (**(code **)(*param_1 + 0x100))(param_2[1],param_2[2],param_2[3]);
    break;
  case 0x13:
    uVar2 = (**(code **)(*param_1 + 0x134))(param_2[1]);
    break;
  case 0x14:
    uVar2 = (**(code **)(*param_1 + 0x130))(param_2[1]);
    break;
  case 0x17:
    uVar2 = (**(code **)(*param_1 + 0x108))(param_2[1],param_2[2],param_2[3]);
    break;
  case 0x18:
    uVar2 = (**(code **)(*param_1 + 0x10c))(param_2[1],param_2[2],param_2[3]);
    break;
  case 0x19:
    (**(code **)(*param_1 + 0x118))();
    uVar2 = 1;
  }
  return uVar2;
}

