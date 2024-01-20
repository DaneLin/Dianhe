#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include "backend/instance.h"

namespace xihe
{
class Window
{
  public:
	struct Extent
	{
		uint32_t width;
		uint32_t height;
	};

	enum class Mode
	{
		kHeadless,
		kFullscreen,
		kFullscreenBorderless,
		kFullscreenStretch,
		kDefault
	};

	enum class Vsync
	{
		OFF,
		ON,
		kDefault
	};

	struct Properties
	{
		std::string title;
		Mode        mode      = Mode::kDefault;
		bool        resizable = true;
		Vsync       vsync     = Vsync::kDefault;
		Extent      extent    = {1280, 720};
	};

	virtual VkSurfaceKHR create_surface(backend::Instance &instance) = 0;

	virtual std::vector<const char *> get_required_surface_extensions() const = 0;

	const Extent &get_extent() const;

	Mode get_window_mode() const;

	const Properties &get_properties() const
	{
		return properties_;
	}

  protected:
	Properties properties_;
};
}        // namespace xihe
